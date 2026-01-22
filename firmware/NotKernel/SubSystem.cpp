#include "NotKernel/SubSystem.hpp"
#include "NotKernel/SubModuleRegistry.hpp"
#include "Events/Frame/types.hpp"
#include "Events/Frame/event.hpp"

typedef Registry<std::string, BasicSubModule> submodregistry;

void SubSystem::init(){

    /*
     * INTERNAL 
    */    

    submodregistry regis = registerShit();

    for (auto it = regis.begin();it != regis.end() ; it++) {
        std::string str = it->first;
        BasicSubModule val = it->second; 

        this->submanager.registerMod(it->first, it->second);
    } 

    this->submanager.initMods();

    this->submanager.getEmitter.subscribe(
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

        case MODSTARTED: 
            //this->submanager->start(ev.getData().data.name);
            //im fuckin stupid this need to move to internals once i do get around to doing that
            break;

        case MODSTOPED:
            //this->submanager->stop(ev.getData().data.name);
            break;

        default: 
            break;
    }
}
