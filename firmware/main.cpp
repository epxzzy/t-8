#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "tasks/log_task.hpp"

extern "C" void app_main(void);

void hello_task(void* arg) {
    while (true) {
        printf("sup bitches\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

extern "C" void app_main(void) {
    /*
    
    xTaskCreate(
        hello_task,      
        "hello_task",   
        2048,            
        //stack size in bytes
        nullptr,         
        //params
        1,              
        //priority
        nullptr          
        //task handle
    );
   */ 
    static LogTask task;
    task.start();

}

