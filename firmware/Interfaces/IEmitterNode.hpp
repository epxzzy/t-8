#pragma once

#include "Events/BasicEmitter.hpp"
#include "Events/Frame/emitter.hpp"


class IEmitterNode {
public:
    BasicEmitter& getEmitter(){
        return this->Emitter;
    };

    virtual EventType getEventType() = 0;

    virtual void emit(Event ev){
        (this->getEmitter()).emit(ev);
    }

    virtual ~IEmitterNode() = default;

private:
    BasicEmitter Emitter;

};
