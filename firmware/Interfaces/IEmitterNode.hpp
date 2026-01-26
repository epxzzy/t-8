#pragma once

#include "Events/BasicEmitter.hpp"
#include "Events/Frame/emitter.hpp"


class IEmitterNode {
public:
    BasicEmitter Emitter;

    BasicEmitter& getEmitter(){
        return this->Emitter;
    };

    EventType getEventType();

    void emit(Event ev){
        this->getEmitter().emit(ev);
    }
};
