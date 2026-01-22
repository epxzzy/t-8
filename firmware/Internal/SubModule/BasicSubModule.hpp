#pragma once

#include "Events/BasicEmitter.hpp"
#include "Events/Frame/types.hpp"

class BasicSubModule {

public:
    BasicEmitter subModEmitter;
    
    BasicSubModule(){};

    BasicEmitter getEmitter(){
        return this->subModEmitter;
    }

    void init();
    void start();
    void tick();
    void stop();

    EventType getEventType();

protected:

private:
    void emit(Event ev){
        this->subModEmitter.emit(ev);
    };

};