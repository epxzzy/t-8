#pragma once

#include "Directive/directive.hpp"
#include "Events/BasicEmitter.hpp"
#include "Events/Frame/emitter.hpp"
#include "Interfaces/IDirectiveNode.hpp"
#include "Interfaces/IEmitterNode.hpp"

class SystemController: public IDirectiveNode<SystemController>, public IEmitterNode {
public:
    using IDirectiveNode<SystemController>::registerHandler;

    EventType getEventType(){
        return EventType::ALL; 
    }

    DirectiveScope getScope(){
        return DirectiveScope::SYSTEMCONTROLLER;
    }

    SystemController(){
        IDirectiveNode<SystemController>::registerHandler(
            DirectiveType::GENERIC_OUTPUT,
            [](SystemController& node, const Directive& dv){
                auto& self = static_cast<SystemController&>(node);
                return self.outputGeneric(dv);
            }
        );
    }

    //void output(std::string string);
    bool outputGeneric(const Directive& dv);

protected:

private:
    bool additionalHandling(Directive& ev){
        return false;        
        //TODO: generate event here prob idk just somehow tell subsystem that directive cant be handled lmao
    };
    void handleExternalEvent(Event ev);

};