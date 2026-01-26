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

    virtual void init();
    virtual void start();
    virtual void tick();
    virtual void stop();
    virtual void handleOrSink(Directive dv);

    virtual EventType getEventType();

protected:

};