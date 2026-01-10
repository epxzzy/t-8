#include "tasks/log_task.hpp"
#include "freertos/projdefs.h"
#include "tasks/base.hpp"
#include <stdio.h>

LogTask::LogTask()
    : TaskBase(
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