#pragma once

#include "events/BasicEmitter.hpp"

class BasicSubModule {

public:
    BasicEmitter subEmitter;
    void init();
    void start();
    void tick(){}
    void stop(){}
    void emit(){}

protected:

private:

};