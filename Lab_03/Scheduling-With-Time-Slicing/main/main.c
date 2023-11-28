#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_freertos_hooks.h"
#include "sdkconfig.h"
#include "esp_log.h"
#include "esp_timer.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include "FreeRTOSConfig.h"

volatile uint32_t ulIdleCycleCount = 0UL;
volatile uint32_t task1CycleCount = 0UL;
volatile uint32_t task2CycleCount = 0UL;

void vApplicationIdleHook(void) {
    ulIdleCycleCount++;
}

// print infomations when two tasks are running
void printCounter() {
    printf("--------------------------------------\n");
    printf("Task1 is Counting: %ld/9622100\n",task1CycleCount);
    printf("Task2 is Counting: %ld/7433210\n",task2CycleCount);
    printf("Idle count: %ld\n", ulIdleCycleCount);
    printf("--------------------------------------\n");
}

/*
    Task 1:
    Print the counting from 1 to 9622100
    Print the counter of two task before task 1 start and after task 1 completed
*/
void Task1(void){
    printf("======================================\n");
    printf("Task 1 will be started!\n\n");
    printf("The state of Task1's counter before it started\n");
    printCounter();
    printf("======================================\n");
    int64_t begin_time = esp_timer_get_time();

    while (1) {
        /* code */
        task1CycleCount++;
        if(task1CycleCount >= 9622100) {
            int64_t end_time = esp_timer_get_time();
            printf("======================================\n");
            printf("Task 1 has terminated during: %lld ms\n", (end_time-begin_time)/1000);
            printf("======================================\n");
            printf("Task 1 has ended!\n");
            printf("Result of 2 tasks with time-slicing:\n");
            printCounter();
            printf("======================================\n");
            vTaskDelete(NULL);
        }
    }
}

/*
    Task 2:
    Print the counting from 1 to 7433210
    Print the counter of two task before task 2 start and after task 2 completed
*/
void Task2(void){
    printf("======================================\n");
    printf("Task 2 will be started!\n\n");
    printf("The state of Task2's counter before it started\n");
    printCounter();
    printf("======================================\n");
    int64_t begin_time = esp_timer_get_time();

    while (1) {
        /* code */
        task2CycleCount++;
        if(task2CycleCount >= 7433210){
            int64_t end_time = esp_timer_get_time();
            printf("======================================\n");
            printf("Task 2 has terminated during: %lld ms\n", (end_time-begin_time)/1000);
            printf("======================================\n");
            printf("Task 2 has ended!\n");
            printf("Result of 2 tasks with time-slicing:\n");
            printCounter();
            printf("======================================\n");
            vTaskDelete(NULL);
        }
    }
}

void app_main() {
    esp_register_freertos_idle_hook_for_cpu(vApplicationIdleHook, 0);
    vTaskDelay(100 / portTICK_PERIOD_MS);
    xTaskCreatePinnedToCore(Task1, "Task1", 5120, NULL, 1, NULL, 0);
    xTaskCreatePinnedToCore(Task2, "Task2", 5120, NULL, 1, NULL, 0);
}

