#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <freertos/FreeRTOS.h>
#include <freertos/queue.h>
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include "esp_timer.h"

struct QueueData
{
    int requestID;
    char message[20];
    char reject;
};

struct TaskType
{
    int taskID;
    char taskName[20];
};

QueueHandle_t xQueue;

struct TaskType Task1 = {.taskName = "Task 1", .taskID = 0};
struct TaskType Task2 = {.taskName = "Task 2", .taskID = 1};
struct TaskType Task3 = {.taskName = "Task 3", .taskID = 2};

void xQueue_manager(void *pvParameter)
{
    xQueue = xQueueCreate(10, sizeof(struct QueueData *));
    if (xQueue == NULL)
    {
        printf("Failed to create queue: not enough RAM.\n");
    }
    vTaskDelete(NULL);
}

void reception_Task(void *pvParameter)
{
    time_t t;
    srand((unsigned)time(&t));

    for (;;)
    {
        while (xQueue == NULL)
        {
            // do nothing
        }

        int randomTask = (rand() % 4);
        int randomDelayOfTask = (rand() % 5) + 1;

        struct QueueData *xData = malloc(sizeof(struct QueueData));

        if (xData != NULL)
        {
            switch (randomTask)
            {
            case 0:
                xData->requestID = 0;
                strcpy(xData->message, "TASK 1");
                xData->reject = 0;
                break;
            case 1:
                xData->requestID = 1;
                strcpy(xData->message, "TASK 2");
                xData->reject = 0;
                break;
            case 2:
                xData->requestID = 2;
                strcpy(xData->message, "TASK 3");
                xData->reject = 0;
                break;
            case 3:
                xData->requestID = 99;
                strcpy(xData->message, "No Task");
                xData->reject = 0;
            break;
            // default:
            //     break;
            }

            if (xQueueSend(xQueue, (void **)&xData, 100) == errQUEUE_FULL)
            {
                printf("Failed to Import Task with ID %d\n", randomTask);
            }
        }
        else
        {
            printf("Can't allocate new struct.\n");
        }
        vTaskDelay(pdMS_TO_TICKS(100 * randomDelayOfTask));
    }
    vTaskDelete(NULL);
}

void active_Task(void *pvParameter)
{
    for (;;)
    {
        struct TaskType *task = (struct TaskType *)pvParameter;
        struct QueueData *pRxMessage;

        if (xQueue != NULL)
        {
            if (xQueueReceive(xQueue, &pRxMessage, (TickType_t)10) == pdPASS)
            {
                if (pRxMessage->requestID == task->taskID)
                {
                    printf("%s\n", pRxMessage->message);
                    free(pRxMessage);
                }
                else
                {
                    printf("%s: received %s, but it's not my task.\n", task->taskName, pRxMessage->message);
                    if (pRxMessage->reject < 2)
                    {
                        pRxMessage->reject++;
                        xQueueSendToFront(xQueue, (void **)&pRxMessage, (TickType_t)10);
                    }
                    else
                    {
                        printf("This task %s is rejected %d times, skipping the task.\n", pRxMessage->message, pRxMessage->reject);
                        free(pRxMessage);
                    }
                }
            }
            else
            {
                // printf("%s: queue empty.\n", task->taskName);
            }
        }
        vTaskDelay(pdMS_TO_TICKS(10));
    }
    vTaskDelete(NULL);
}

void app_main(void)
{
    xTaskCreate(&xQueue_manager, "queue_manager", 2048, NULL, 10, NULL);
    xTaskCreate(&reception_Task, "rec", 2048, NULL, 10, NULL);
    xTaskCreate(&active_Task, "Task 1", 2048, (void *)&Task1, 10, NULL);
    xTaskCreate(&active_Task, "Task 2", 2048, (void *)&Task2, 10, NULL);
    xTaskCreate(&active_Task, "Task 3", 2048, (void *)&Task3, 10, NULL);
    vTaskDelay(1000);
}
