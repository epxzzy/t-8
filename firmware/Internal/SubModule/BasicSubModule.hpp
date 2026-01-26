#pragma once

#include "Directive/directive.hpp"
#include "Directive/types.hpp"
#include "Events/BasicEmitter.hpp"
#include "Events/Frame/types.hpp"

class BasicSubModule {

public:
    BasicEmitter subModEmitter;
    
    BasicSubModule(){};

    BasicEmitter getEmitter(){
        return this->subModEmitter;
    }

    DirectiveScope getScope(){
        return DirectiveScope::SUBMODULE;
    }

    bool canHandle(Directive dv){
        return dv.scope == this->getScope();
    }

    virtual void init();
    virtual void start();
    virtual void tick();
    virtual void stop();
    virtual void handleOrSink(Directive dv);

    virtual EventType getEventType();

protected:

private:
    void emit(Event ev){
        this->subModEmitter.emit(ev);
    };

};