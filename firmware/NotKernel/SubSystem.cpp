#include "NotKernel/SubSystem.hpp"
#include "NotKernel/SubModuleRegistry.hpp"
#include "Events/Frame/types.hpp"
#include "Events/Frame/event.hpp"
#include "nvs_flash.h"

typedef Registry<std::string, BasicSubModule*> submodregistry;

void SubSystem::init(){
    nvs_flash_init();
    /*
     * INTERNAL 
    */    

    submodregistry regis = registerShit();

    for (auto it = regis.begin();it != regis.end() ; it++) {
        std::string str = it->first;
        BasicSubModule* val = it->second; 

        this->submanager.registerMod(str, val);
    } 

    this->submanager.initMods();

    this->submanager.getEmitter().subscribe(
        "SubManager",
        this->submanager.getEventType(),
        [this](const Event* ev) {
            this->handleInternalEvent(*ev);
        }
    );

    //start called later cause modules can be
    //hotswapped and would fuck with emitters
    this->submanager.startMods();

    /*
     * EXTERNAL
    */    
    
}

void SubSystem::tick(){
    this->submanager.tickMods();
}

void SubSystem::handleInternalEvent(Event ev){
    switch (ev.getType()) {

        case MOD_STARTED: 
            //this->submanager->start(ev.getData().data.name);
            //im fuckin stupid this need to move to internals once i do get around to doing that
            break;

        case MOD_STOPED:
            //this->submanager->stop(ev.getData().data.name);
            break;

        default: 
            break;
    }
}
