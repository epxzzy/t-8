#include "NotKernel/SubSystem.hpp"
#include "Directive/directive.hpp"
#include "NotKernel/SubModuleRegistry.hpp"
#include "Events/Frame/types.hpp"
#include "Events/Frame/event.hpp"
#include "nvs_flash.h"

typedef Registry<std::string, AbstractSubModule*> submodregistry;

void SubSystem::init(){
    nvs_flash_init();
    /*
     * INTERNAL 
    */    

    submodregistry regis = registerShit();

    for (auto it = regis.begin();it != regis.end() ; it++) {
        std::string str = it->first;
        AbstractSubModule* val = it->second; 

        this->submanager.registerMod(str, val);
    } 

    this->submanager.initMods();

    this->submanager.getEmitter().subscribe(
        "SubManager",
        this->submanager.getEventType(),
        [this](const Event* ev) {
            this->handleInternalEvent(ev);
        }
    );

    //start called later cause modules can be
    //hotswapped and would fuck with emitters
    this->submanager.startMods();

    /*
     * EXTERNAL
    */    

    this->syscontroller.getEmitter().subscribe(
        "SystemController",
        this->syscontroller.getEventType(),
        [this](const Event* ev) {
            this->handleExternalEvent(ev);
        }
    );
    
}

void SubSystem::tick(){
    this->submanager.tickMods();
}

void SubSystem::handleInternalEvent(const Event* ev){
    switch (ev->getType()) {
        case MOD_STARTED: 
            //sinkExternal(dv);
            break;

        case MOD_STOPED:
            //sinkExternal(dv);
            break;

        default: 

            break;
    }
}

void SubSystem::handleExternalEvent(const Event* ev){
    switch (ev->getType()) {
        case EventType::TOOL_SUCCESS: 
            //make a jingle or something idk
            break;

        case EventType::TOOL_FAILURE:
            //ohh ouh- STINKYYY
            break;

        case EventType::TOOL_LIMBO:
            //something is up, prob waiting on input
            break;
        case EventType::TOOL_IHADENOUGH:
            //me too buddy me too
            break;

        default: 
            break;
    }
}

bool SubSystem::sinkExternal(Directive& dv){
    return this->syscontroller.handle(dv);
}
bool SubSystem::sinkInternal(Directive& dv){
    return this->submanager.handle(dv);
}
