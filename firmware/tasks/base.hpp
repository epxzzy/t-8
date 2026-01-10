#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "portmacro.h"
#include <cstdint>

class TaskBase {

public: 
    TaskBase(const char* name, uint32_t stack, UBaseType_t priority);

    //~TaskBase();  
    void start();
    
protected: 
    virtual void run() = 0;
    // = 0 means abstract

private: 
    static void task_entry(void* arg);

    const char* name;
    uint32_t stack;
    UBaseType_t priority;
    TaskHandle_t handle = nullptr;
};