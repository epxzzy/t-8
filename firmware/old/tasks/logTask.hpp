#pragma once

#include "./baseTask.hpp"

class LogTask: public BaseTask {
public:
    LogTask();
    void run() override;

};