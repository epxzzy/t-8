#include "tasks/baseTask.hpp"

#include "freertos/idf_additions.h"

BaseTask::BaseTask(const char* name, uint32_t stack, UBaseType_t priority)
: name(name), stack(stack), priority(priority) {};

void BaseTask::start(){
    xTaskCreate(
        &BaseTask::task_entry,
        name,
        stack,
        this,
        priority,
        &handle 
    );
}

void BaseTask::task_entry(void* arg){
    static_cast<BaseTask*>(arg) -> run();
    vTaskDelete(nullptr);
}