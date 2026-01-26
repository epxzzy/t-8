#pragma once

#include "Directive/directive.hpp"
#include "Events/BasicEmitter.hpp"
#include "Events/Frame/emitter.hpp"
#include "Interfaces/IDirectiveNode.hpp"
#include "Interfaces/IEmitterNode.hpp"

class SystemController: public IEmitterNode, public IDirectiveNode {

public:
    void output(std::string string);

    EventType getEventType(){
        return EventType::ALL; 
    }

    DirectiveScope getScope(){
        return DirectiveScope::SYSTEMCONTROLLER;
    }

protected:

private:
    void handleOrSink(Directive ev);
    void handleExternalEvent(Event ev);

};