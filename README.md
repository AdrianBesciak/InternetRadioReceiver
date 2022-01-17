# Internet Radio Receiver

Internet Radio Receiver is an internet radio project, targeting STM32F746G-Disco platform.
It is written in C++17 and C11, using CMake build system,
along with STM32CubeMX and TouchGFXDesigner configuration tools.
It provides ability to listen to internet radio stations via ethernet interface, or to music files from
external microSD card. It supports Wave and MPEG Audio formats.

## Requirements

To compile the project install following dependencies:

- [GNU Arm Embedded Toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads)
- [OpenOCD](https://openocd.org/)
- [CMake](https://cmake.org/download/)

To start working on the project install also:

- [STM32CubeMX](https://www.st.com/en/development-tools/stm32cubemx.html)
- [TouchGFXDesigner](https://www.st.com/en/development-tools/touchgfxdesigner.htmlhttps://www.st.com/en/development-tools/touchgfxdesigner.html)

## Building

### Manually

```shell
git clone "https://github.com/AdrianBesciak/InternetRadioReceiver"
cd "InternetRadioReceiver"
mkdir "build"
cd "build"
cmake ..
cmake --build . --config Release
```

When the build finishes, in the current working directory there should be `InternetRadioReceiver.elf` file.


### With CLion

1. Open project with CLion.
2. Wait for CMake configuration.
3. To build in release add Release CMake configuration in CLion settings.
4. Create OpenOCD run configuration using `board/stm32f746g-disco.cfg` board file.
5. Project should be ready to build and install on the board.
