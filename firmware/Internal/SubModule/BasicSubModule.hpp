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

    virtual void init();
    virtual void start();
    virtual void tick();
    virtual void stop();

    virtual EventType getEventType();

protected:

private:
    void emit(Event ev){
        this->subModEmitter.emit(ev);
    };

};