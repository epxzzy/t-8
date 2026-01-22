#include "SystemController.hpp"
#include "Events/Frame/event.hpp"
#include "Events/Frame/types.hpp"
#include <cstdio>

void SystemController::output(std::string string){
    printf("out: %s", string.data());
}

void SystemController::handleExternalEvent(Event ev){

}

void SystemController::handleTheCommandSystemThatDoesNotFuckingExistAsOfThisCommitSoIWillJustUseEventsAsAnPlaceHolder(Event ev){
    EventType type = ev.getType();

    if(type == EventType::LOG){
        LogData logdat = ExtractLogEventData(ev.getData());
        this->output(logdat.message);
    }
}
