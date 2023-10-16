# Embedded System Lab 02: ESP32 GPIO and FreeRTOS task
* Description:
  * Read the input from or write the output to an GPIO pin.
  * Create, schedule, and delete FreeRTOS tasks on the ESP32 development board.
  * Complete the final exercise of the lab with the following content:
    * Students create 2 tasks and schedule them using FreeRTOS’s task management
functions: <br>
      • A cyclic task printing your student identifier every second. <br>
      • An acyclic task polling a button and print "ESP32" every when the button 
is pressed. <br>
* Preparation:
   * IDE and Extensions (We use VSCode and Espressif IDF, You can reference from [here](https://github.com/nghiemluongson/embedded_System_All_Labs))
   * ESP32 Wifi Bluetooth UNO R3 (You also use another version of ESP32, this device that you can buy [here](https://www.thegioiic.com/carts?gidzl=HmRp4B5YmJX64VGJk7h9E4uKzH6dVCKwLKJtGQKen6e34Vb1_7JBFWjBhXhuSyan3agf6JV7NGGTicF1Fm)) <br>
     ![Lab2](https://github.com/nghiemluongson/embedded_System_All_Labs/blob/d2adfe367b459d4c60d84c6d9baeecdbe11bceab/Images/Lab%201/5.jpg)
* Exercise:
  * Coding in the main folder, file lab2.c <br>
    ![Lab2](https://github.com/nghiemluongson/embedded_System_All_Labs/blob/f1461f17d3eeb034fb9ff84f1c4730e580883345/Images/Lab%202/2.jpg)
  * Use a command terminal to execute the program include build, flash and monitor (Note: In which <COM> represents the port connected to the ESP32 on the device.): <br>
     ### `idf.py build ; idf.py -p <COM> flash ; idf.py -p <COM> monitor`
  *  Real-life image of ESP32 connected with a button: <br>
  ![Lab2](https://github.com/nghiemluongson/embedded_System_All_Labs/blob/20a244b72a6e158717051f9161d79201eb9f97a6/Images/Lab%202/1.jpg)
  * You also can reference the README.md from the development team below:<br>
  | Supported Targets | ESP32 | ESP32-C2 | ESP32-C3 | ESP32-C6 | ESP32-H2 | ESP32-S2 | ESP32-S3 |
  | ----------------- | ----- | -------- | -------- | -------- | -------- | -------- | -------- |
* Result:
  * Result of Task 1: print student's identifier every second.<br>
  ![Lab2](https://github.com/nghiemluongson/embedded_System_All_Labs/blob/f1461f17d3eeb034fb9ff84f1c4730e580883345/Images/Lab%202/3.jpg)
  * Result of Task 2:print "ESP32" every when the button is pressed.<br>
  ![Lab2](https://github.com/nghiemluongson/embedded_System_All_Labs/blob/f1461f17d3eeb034fb9ff84f1c4730e580883345/Images/Lab%202/4.jpg)
# _Sample project_

(See the README.md file in the upper level 'examples' directory for more information about examples.)

This is the simplest buildable example. The example is used by command `idf.py create-project`
that copies the project to user specified path and set it's name. For more information follow the [docs page](https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html#start-a-new-project)



## How to use example
We encourage the users to use the example as a template for the new projects.
A recommended way is to follow the instructions on a [docs page](https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html#start-a-new-project).

## Example folder contents

The project **sample_project** contains one source file in C language [main.c](main/main.c). The file is located in folder [main](main).

ESP-IDF projects are built using CMake. The project build configuration is contained in `CMakeLists.txt`
files that provide set of directives and instructions describing the project's source files and targets
(executable, library, or both). 

Below is short explanation of remaining files in the project folder.

```
├── CMakeLists.txt
├── main
│   ├── CMakeLists.txt
│   └── main.c
└── README.md                  This is the file you are currently reading
```
Additionally, the sample project contains Makefile and component.mk files, used for the legacy Make based build system. 
They are not used or needed when building with CMake and idf.py.