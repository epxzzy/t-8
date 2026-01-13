#pragma once

#include "tasks/baseTask.hpp"

class LogTask: public BaseTask {
public:
    LogTask();
    void run() override;

};