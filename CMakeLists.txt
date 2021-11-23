cmake_minimum_required(VERSION 3.19)
include(cmake/CrossCompile.cmake)
project(InternetRadioReceiver C CXX ASM)

#add_subdirectory(SpiritMP3Dec)
add_subdirectory(StdVorbisDec)

# Executable
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS
        Core/*.c
        Core/*.s
        Drivers/*.c
        Middlewares/*.c
        Middlewares/ST/touchgfx/framework/source/touchgfx/*.cpp
        FATFS/*.c
        LWIP/*.c
        Radio/*.cpp
        InternetConnection/*.c
        InternetConnection/*.cpp
        TouchGFX/App/*.c
        TouchGFX/App/*.cpp
        TouchGFX/generated/fonts/*.c
        TouchGFX/generated/fonts/*.cpp
        TouchGFX/generated/gui_generated/*.c
        TouchGFX/generated/gui_generated/*.cpp
        TouchGFX/generated/images/*.c
        TouchGFX/generated/images/*.cpp
        TouchGFX/generated/texts/*.c
        TouchGFX/generated/texts/*.cpp
        TouchGFX/generated/videos/*.c
        TouchGFX/generated/videos/*.cpp
        TouchGFX/gui/*.c
        TouchGFX/gui/*.cpp
        TouchGFX/target/*.c
        TouchGFX/target/*.cpp
        )
file(GLOB_RECURSE PROJECT_HEADERS CONFIGURE_DEPENDS
        Core/*.h
        Drivers/*.h
        Middlewares/*.h
        FATFS/*.h
        LWIP/*.h
        Radio/*.hpp
        TouchGFX/*.h
        TouchGFX/*.hpp
        )
set(PROJECT_LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/STM32F746NGHX_FLASH.ld)
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS} ${PROJECT_LINKER_SCRIPT})
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "${PROJECT_NAME}.elf")

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
        Core/Inc
        Drivers/BSP/Components
        Drivers/BSP/Components/ft5336
        Drivers/BSP/Components/wm8994
        Drivers/BSP/STM32746G-Discovery
        Drivers/CMSIS/Include
        Drivers/CMSIS/Device/ST/STM32F7xx/Include
        Drivers/ft5336
        Drivers/STM32F7xx_HAL_Driver/Inc
        Drivers/STM32F7xx_HAL_Driver/Inc/Legacy
        Middlewares/Third_Party/FreeRTOS/Source/include
        Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1
        FATFS/App
        FATFS/Target
        LWIP/App
        LWIP/Target
        Middlewares/Third_Party/FatFs/src
        Middlewares/Third_Party/LwIP/system
        Middlewares/Third_Party/LwIP/src/api
        Middlewares/Third_Party/LwIP/src/apps
        Middlewares/Third_Party/LwIP/src/core
        Middlewares/Third_Party/LwIP/src/include
        Middlewares/Third_Party/LwIP/src/netif
        Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2
        Middlewares/ST/touchgfx/3rdparty/libjpeg/include
        Middlewares/ST/touchgfx/framework/include
        Radio
        TouchGFX/App
        TouchGFX/generated/fonts/include
        TouchGFX/generated/gui_generated/include
        TouchGFX/generated/images/include
        TouchGFX/generated/texts/include
        TouchGFX/generated/videos/include
        TouchGFX/gui/include
        TouchGFX/target
        TouchGFX/target/generated
        SpiritMP3Dec/include
        )

# Definitions
target_compile_definitions(${PROJECT_NAME} PRIVATE
        DEBUG
        USE_HAL_DRIVER
        STM32F746xx
        )


# Language version
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
target_compile_features(${PROJECT_NAME} PUBLIC c_std_11)
set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
        )


# Warnings
target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall
        -Wextra
        -Wno-unused-parameter
        $<$<COMPILE_LANGUAGE:CXX>:-pedantic>
        $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
        $<$<COMPILE_LANGUAGE:C>:-Wno-unused-variable>
        $<$<COMPILE_LANGUAGE:C>:-Wno-int-conversion>
        )

# Link options
target_link_libraries(${PROJECT_NAME} PUBLIC
        #SpiritMP3Dec
        StdVorbisDec
        ${PROJECT_SOURCE_DIR}/TouchGFX/libtouchgfx.a)
target_link_options(${PROJECT_NAME} PRIVATE -Wl,-Map=${PROJECT_BINARY_DIR}/${PROJECT_NAME}.map)
target_link_options(${PROJECT_NAME} PRIVATE -T ${PROJECT_LINKER_SCRIPT})

# Output files
set(HEX_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.hex)
set(BIN_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.bin)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -Oihex $<TARGET_FILE:${PROJECT_NAME}> ${HEX_FILE}
        COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:${PROJECT_NAME}> ${BIN_FILE})
