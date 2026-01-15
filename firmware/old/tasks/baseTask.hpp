#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "portmacro.h"
#include <cstdint>

class BaseTask {
public: 
    BaseTask(
        const char* name,
        uint32_t stack,
        UBaseType_t priority
    );

    //~TaskBase();  
    void start();

protected:
    virtual void run() = 0;
    // = 0 means abstract

    const char *name;
    uint32_t stack;
    UBaseType_t priority;
    TaskHandle_t handle = nullptr;

private:
    static void task_entry(void *arg);
};