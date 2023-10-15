# Embedded System Lab 01: Introduction to ESP32 and ESP-IDF
* Description:
   * Getting started with the ESP32 board.
   * Familiarizing yourself with ESP-IDF.
   * Build and flash the "Hello world!" example to the ESP32 development board successfully.
* Preparation:
   * IDE and Extensions (We use VSCode and Espressif IDF, You can reference from [here](https://github.com/nghiemluongson/embedded_System_All_Labs))
   * ESP32 Wifi Bluetooth UNO R3 (You also use another version of ESP32, this device that you can buy [here](https://www.thegioiic.com/carts?gidzl=HmRp4B5YmJX64VGJk7h9E4uKzH6dVCKwLKJtGQKen6e34Vb1_7JBFWjBhXhuSyan3agf6JV7NGGTicF1Fm)) <br>
     ![Lab1](https://github.com/nghiemluongson/embedded_System_All_Labs/blob/d2adfe367b459d4c60d84c6d9baeecdbe11bceab/Images/Lab%201/5.jpg)
* Flash and Build "Hello World" Project:
   * First, make sure the device is fully connected and the correct COM port is selected.
   * You can use ESP-IDF Powershell:
     * Link to your file code, open it with terminal.
     * Build:<br>
       ![Lab1](https://github.com/nghiemluongson/embedded_System_All_Labs/blob/d2adfe367b459d4c60d84c6d9baeecdbe11bceab/Images/Lab%201/6.jpg)
     * Flash:<br>
       ![Lab1](https://github.com/nghiemluongson/embedded_System_All_Labs/blob/d2adfe367b459d4c60d84c6d9baeecdbe11bceab/Images/Lab%201/7.jpg)
     * Monitor device to view the result in the terminal:<br>
       ![Lab1](https://github.com/nghiemluongson/embedded_System_All_Labs/blob/d2adfe367b459d4c60d84c6d9baeecdbe11bceab/Images/Lab%201/8.jpg)
    
* You also can reference the README.md from the development team below:<br>
| Supported Targets | ESP32 | ESP32-C2 | ESP32-C3 | ESP32-C6 | ESP32-H2 | ESP32-S2 | ESP32-S3 |
| ----------------- | ----- | -------- | -------- | -------- | -------- | -------- | -------- |

# Hello World Example

Starts a FreeRTOS task to print "Hello World".

(See the README.md file in the upper level 'examples' directory for more information about examples.)

## How to use example

Follow detailed instructions provided specifically for this example.

Select the instructions depending on Espressif chip installed on your development board:

- [ESP32 Getting Started Guide](https://docs.espressif.com/projects/esp-idf/en/stable/get-started/index.html)
- [ESP32-S2 Getting Started Guide](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s2/get-started/index.html)


## Example folder contents

The project **hello_world** contains one source file in C language [hello_world_main.c](main/hello_world_main.c). The file is located in folder [main](main).

ESP-IDF projects are built using CMake. The project build configuration is contained in `CMakeLists.txt` files that provide set of directives and instructions describing the project's source files and targets (executable, library, or both).

Below is short explanation of remaining files in the project folder.

```
├── CMakeLists.txt
├── pytest_hello_world.py      Python script used for automated testing
├── main
│   ├── CMakeLists.txt
│   └── hello_world_main.c
└── README.md                  This is the file you are currently reading
```

For more information on structure and contents of ESP-IDF projects, please refer to Section [Build System](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/build-system.html) of the ESP-IDF Programming Guide.

## Troubleshooting

* Program upload failure

    * Hardware connection is not correct: run `idf.py -p PORT monitor`, and reboot your board to see if there are any output logs.
    * The baud rate for downloading is too high: lower your baud rate in the `menuconfig` menu, and try again.

## Technical support and feedback

Please use the following feedback channels:

* For technical queries, go to the [esp32.com](https://esp32.com/) forum
* For a feature request or bug report, create a [GitHub issue](https://github.com/espressif/esp-idf/issues)

We will get back to you as soon as possible.
