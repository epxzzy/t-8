#include "./logTask.hpp"
#include "freertos/projdefs.h"
#include "./baseTask.hpp"
#include <stdio.h>

LogTask::LogTask()
    : BaseTask(
        "hellotask",
        2048,
        1
    ){}


void LogTask::run(){
    while(true){
        printf("sup biatches\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}