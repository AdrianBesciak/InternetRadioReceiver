#include "../include/ethernet.hpp"
#include <cstdio>


extern struct netif gnetif;
constexpr uint32_t CITY_NAME_BUFFEL_LEN = 0x20;
static char cityNameBuffer[CITY_NAME_BUFFEL_LEN] = {};
static char cityNameBufferEscaped[CITY_NAME_BUFFEL_LEN * 3 + 1];
extern TaskHandle_t internetTask;

void dhcp_get_address() {
    struct dhcp *dhcp = netif_dhcp_data(&gnetif);
    do {
        printf("dhcp->state = %02X\n", dhcp->state);
        vTaskDelay(500);
    } while (dhcp->state != 0x0A);

    printf("Got IP addr: %s\n", ipaddr_ntoa(&gnetif.ip_addr));
}

void cleanup_socket(int sock) {
    shutdown(sock, SHUT_RDWR);
    close(sock);
}

int getData(const char *location) {
    if(strlen(location) == 0){
        return 1;
    }

    constexpr int RECV_BUFFER_SIZE = 1'600;
    static char recv_buffer[RECV_BUFFER_SIZE];
    static char url[0x100];

    const char *firstPart = "GET http://api.openweathermap.org/data/2.5/weather?q=";
    const char *secondPart = "&units=metric&lang=pl&appid=839d6df972338bb98ae9a6dbf710ad81\r\n\r\n";

    snprintf(url, 0x100, "%s%s%s", firstPart, cityNameBufferEscaped, secondPart);
    printf("Getting data for %s\n", location);

    ip4_addr_t serverIP;
    constexpr u16_t serverPort = 80;

    if (netconn_gethostbyname("api.openweathermap.org", &serverIP) != ERR_OK) {
        printf("Error getting weather server IP address\n");
        return 2;
    }

    sockaddr_in tcp_server;
    tcp_server.sin_family = AF_INET;
    tcp_server.sin_port = htons(serverPort);
    char serverIPString[16];
    strcpy(serverIPString, ipaddr_ntoa(&serverIP));

    inet_pton(tcp_server.sin_family, serverIPString, &(tcp_server.sin_addr));
    int serverSocket = socket(tcp_server.sin_family, SOCK_STREAM, 0);
    vTaskDelay(1'000);

    if (connect(serverSocket, (struct sockaddr *) &tcp_server, sizeof(tcp_server)) != 0) {
        printf("Error connecting to the server\n");
        return 3;
    }

    vTaskDelay(1'000);

    if (send(serverSocket, url, strlen(url), 0) < 0) {
        printf("Error sending URI)\n");
        return 4;
    }

    vTaskDelay(1'000);

    int receivedCharacters = recv(serverSocket, recv_buffer, RECV_BUFFER_SIZE, 0);
    if (receivedCharacters < 0) {
        printf("Error receiving message\n");
        cleanup_socket(serverSocket);
        return 5;
    }
    if (receivedCharacters == 0) {
        printf("Received empty response\n");
        cleanup_socket(serverSocket);
        return 6;
    }

    cleanup_socket(serverSocket);
    printf("%s\n", recv_buffer);
    return 0;
}

extern "C"
[[noreturn]]
void internetConnectionThread(void *arguments) {
    (void) arguments;
    printf("Internet Connection Thread started\n");

    dhcp_get_address();

    while (true) {
        getData(cityNameBuffer);

        vTaskDelay(15'000);
    }
}

