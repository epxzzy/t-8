#include "base.hpp"
#include "freertos/idf_additions.h"

TaskBase::TaskBase(const char* name, uint32_t stack, UBaseType_t priority)
: name(name), stack(stack), priority(priority) {};

void TaskBase::start(){
    xTaskCreate(
        &TaskBase::task_entry,
        name,
        stack,
        this,
        priority,
        &handle 
    );
}

void TaskBase::task_entry(void* arg){
    static_cast<TaskBase*>(arg) -> run();
    vTaskDelete(nullptr);
}