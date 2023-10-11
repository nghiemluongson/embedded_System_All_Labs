// Libraries needed for the use of FreeRTOS.
#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"

// Library needed for GPIO functions.
#include "driver/gpio.h"

// Macro defining the GPIO for our input button.
#define BUTTON_GPIO 17

// Constant parameter representing active low logic level.
// Defining the value of signal of button
#define button_Is_Pressed 0
#define button_Is_Not_Pressed 1

// This function prints out my student ID every 1 second.
void print_StudentID(void* parameter) {
    while (true) {
        printf("Group_N12 - List members \n");
        printf("Student_1: 2012069 - Tham Le Thi Hong \n");
        printf("Student_2: 2014373 - Son Nghiem Luong \n\n");

        // Wait for 1s.
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    // Delete the task. This will never be reached.
    vTaskDelete(NULL);
}

// This function prints "ESP32" whenever the button connected
// to pin 18 is pressed.
void print_ESP32(void* parameter) {

    // Select pin 17 as a GPIO pin.
    esp_rom_gpio_pad_select_gpio(BUTTON_GPIO);

    // Specify that the pin is an input pin.
    gpio_set_direction(BUTTON_GPIO, GPIO_MODE_INPUT);

    // Specify the pull mode as pullup.
    gpio_set_pull_mode(BUTTON_GPIO, GPIO_PULLUP_ONLY);

    while (true) {
        // When the button is pressed, print out "ESP32".
        if (gpio_get_level(BUTTON_GPIO) == button_Is_Pressed) {
            printf("ESP32 \n");
        }

        // Debounce for 200ms.
        vTaskDelay(200 / portTICK_PERIOD_MS);
    }
    // Delete the task. This will never be reached.
    vTaskDelete(NULL);
}

void app_main(void) {
    // Create the two tasks. printESP32 has a higher priority.

    // print studentID task
    xTaskCreate(print_StudentID, "printStudentID", 1000, NULL, 1, NULL);

    // print "ESP32" task
    xTaskCreate(print_ESP32, "printESP32", 1000, NULL, 2, NULL);
}
