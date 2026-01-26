#pragma once

#include "Directive/directive.hpp"
#include "Events/BasicEmitter.hpp"
#include "Events/Frame/emitter.hpp"

class SystemController {

public:
    BasicEmitter controllerEmitter;
    
    void output(std::string string);

    BasicEmitter getEmitter(){
        return this->controllerEmitter; 
    }

    EventType getEventType(){
        return EventType::ALL; 
    }

    DirectiveScope getScope(){
        return DirectiveScope::SYSTEMCONTROLLER;
    }

    bool canHandle(Directive dv){
        return dv.scope == this->getScope();
    }


protected:

private:
    void handleOrSink(Directive ev);
    void handleExternalEvent(Event ev);

};