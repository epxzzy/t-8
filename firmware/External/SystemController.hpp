#pragma once

#include "Events/BasicEmitter.hpp"
#include "Events/Frame/emitter.hpp"

class SystemController {

public:
    BasicEmitter controllerEmitter;
    
    //todo: make some command system, kinda like the event protocol    
    //need something that sinks down and can be picked up by any members
    //would resolve the need to have fuck ton of methods
    void output(std::string string);

    BasicEmitter getEmitter(){
        return this->controllerEmitter; 
    }

    EventType getEventType(){
        return EventType::ALL; 
    }

protected:

private:
    void handleTheCommandSystemThatDoesNotFuckingExistAsOfThisCommitSoIWillJustUseEventsAsAnPlaceHolder(Event ev);
    void handleExternalEvent(Event ev);

};