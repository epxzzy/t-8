#include "SystemController.hpp"
#include "Directive/directive.hpp"
#include "Events/Frame/event.hpp"
#include "Events/Frame/types.hpp"
#include <cstdio>

/*
void SystemController::output(std::string string){
    printf("out: %s", string.data());
}
*/


bool SystemController::outputGeneric(const Directive& dv){
    printf("generic out: %s", extract(dv.getData()));
    return true;
}

void SystemController::handleExternalEvent(Event ev){
    //TODO: shit here
}

/*
void SystemController::additionalHandling(Directive& dv){
    /*
    EventType type = dv.getType();


    if(type == EventType::LOG){
        LogData logdat = ExtractLogDataPacket(ev.getData());
        this->output(logdat.message);
    }
//}

*/
