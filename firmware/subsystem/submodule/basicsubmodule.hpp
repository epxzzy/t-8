#pragma once

#include "events/BasicEmitter.hpp"

class BasicSubModule {

public:
    BasicEmitter subModEmitter;
    
    BasicSubModule(std::string name){
        this->subModEmitter.subscribe(
            name,
            EventType::ALL,
            [this](const Event* ev) {
                this->handleEvent(*ev);
            }
        );
    }

    void init();
    void start();
    void tick();
    void stop();

    void emit(Event ev){
       this->subModEmitter.emit(ev); 
    }
    void handleEvent(Event ev);

protected:

private:

};