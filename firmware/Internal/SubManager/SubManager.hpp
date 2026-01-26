#pragma once

#include "Directive/types.hpp"
#include "Events/BasicEmitter.hpp"
#include "Events/Frame/event.hpp"
#include "Events/Frame/types.hpp"
#include "Registries/BasicRegistry.hpp"
#include "Internal/SubModule/BasicSubModule.hpp"

typedef Registry<std::string, BasicSubModule> subModReg;

class SubManager {

public:
    BasicEmitter subManEmitter;
    subModReg subManReg;

    std::string registerMod(std::string name,BasicSubModule submod){
        this->subManReg.registerItem(name, submod); 
        return name;
    };

    std::string unregisterMod(std::string name){
        this->subManReg.unregisterItem(name); 
        return name;
    };

    subModReg acquireRegistry(){
        return this->subManReg;
    }

    DirectiveScope getScope(){
        return DirectiveScope::SUBMANAGER;
    }

    bool canHandle(Directive dv){
        return dv.scope == this->getScope();
    }

    BasicEmitter getEmitter(){
        return this->subManEmitter; 
    }

    EventType getEventType(){
        return EventType::ALL; 
    }

    void initMods(){
        for(auto it = this->subManReg.begin();it != this->subManReg.end() ; it++) {
            BasicSubModule val = it->second; 
            val.init();
        };
    };

    void tickMods(){
        for(auto it = this->subManReg.begin();it != this->subManReg.end() ; it++) {
            BasicSubModule val = it->second; 
            val.tick();    
        }
    };

    void startMods(){
        for(auto it = this->subManReg.begin();it != this->subManReg.end() ; it++) {
            this->start(it->first);
        }
    };

    void stopMods(){
        for(auto it = this->subManReg.begin();it != this->subManReg.end() ; it++) {
            this->stop(it->first);
        }
    };

    void start(std::string name){
        BasicSubModule modular = this->subManReg.acquire(name);
        BasicEmitter modularemitter = modular.getEmitter();

        modularemitter.subscribe(
            "SubManager",
            modular.getEventType(),
            [this](const Event* ev) {
                this->handleSubModuleEvent(*ev);
            }
        );

        modular.start();
    };

    void stop(std::string name){
        BasicSubModule modular = this->subManReg.acquire(name);
        BasicEmitter modularemitter = modular.getEmitter();

        modularemitter.unsubscribe(
            "SubManager",
            modular.getEventType()
        );

        modular.stop();
    };

protected:

private:
    void handleSubModuleEvent(const Event ev){
        //TODO: create and bind events to start stop and else.
        //so the tools can fuckin do shit
    };
    void handleOrSink(Directive dv);

    void emit(Event ev){
        this->subManEmitter.emit(ev);
    }
};