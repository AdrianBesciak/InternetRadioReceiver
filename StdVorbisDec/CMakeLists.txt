project(StdVorbisDec)

set(SOURCES src/stb_vorbis.c)
set(HEADERS include/stb_vorbis.h)

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME}
PUBLIC
        include
PRIVATE
        src
)