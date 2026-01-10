#pragma once

#include "tasks/base.hpp"

class LogTask: public TaskBase {
public:
    LogTask();
    void run() override;

};