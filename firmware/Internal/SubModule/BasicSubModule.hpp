#pragma once

#include "Directive/directive.hpp"
#include "Directive/types.hpp"
#include "Events/BasicEmitter.hpp"
#include "Events/Frame/types.hpp"
#include "Interfaces/IDirectiveNode.hpp"
#include "Interfaces/IEmitterNode.hpp"

class BasicSubModule: public IEmitterNode, public IDirectiveNode {

public:
    
    BasicSubModule(){};

    DirectiveScope getScope(){
        return DirectiveScope::SUBMODULE;
    }
    
    virtual EventType getEventType() = 0;

    virtual void init() = 0;
    virtual void start() = 0;
    virtual void tick() = 0;
    virtual void stop() = 0;
    virtual void handleOrSink(Directive dv) = 0;



protected:

};