#pragma once

#include "events/BasicEmitter.hpp"
#include "events/frame/types.hpp"
#include "registries/basicregistry.hpp"
#include "subsystem/submodule/basicsubmodule.hpp"

typedef Registry<std::string, BasicSubModule> subModReg;

class SubManager {

public:
    EventEmitter subManEmitter;
    subModReg subManReg;

    SubManager(){
        //bind emitter
        this->subManEmitter.subscribe(
            "SubManager",
            EventType::ALL,
            [this](const Event* ev) {
                this->handleEvent(*ev);
            }
        );
    };

    ~SubManager(){
        //unbind fucker
        this->subManEmitter.unsubscribe(
            "SubManager",
            EventType::ALL
        );
    }
    
    std::string registermod(std::string name,BasicSubModule submod){
        this->subManReg.registeritem(name, submod); 
        return name;
    };

    std::string unregistermod(std::string name){
        this->subManReg.unregisteritem(name); 
        return name;
    };

    subModReg acquireRegistry(){
        return this->subManReg;
    }

    void init_mods(){
        for(auto it = this->subManReg.begin();it != this->subManReg.end() ; it++) {
            BasicSubModule val = it->second; 
            val.init();
        };
    };

    void start(std::string name){
        BasicSubModule modular = this->subManReg.acquire(name);
        modular.start();
    };

    void stop(std::string name){
        BasicSubModule modular = this->subManReg.acquire(name);
        modular.stop();
    };

    void tick_mods(){
        for(auto it = this->subManReg.begin();it != this->subManReg.end() ; it++) {
            BasicSubModule val = it->second; 
            val.tick();    
        }
    };

    void emit(Event ev){
        this->subManEmitter.emit(ev);
    };
    
    void handleEvent(const Event ev){
        //TODO: create and bind events to start stop and else.
        //so the tools can fuckin do shit
    };

protected:

private:

};