#pragma once

#include "Directive/directive.hpp"
#include "Directive/types.hpp"
#include "Events/BasicEmitter.hpp"
#include "Events/Frame/event.hpp"
#include "External/SystemController.hpp"
#include "Internal/SubManager/SubManager.hpp"

class SubSystem {

public:
    SubManager submanager;
    SystemController syscontroller;
    void init();
    void tick();

protected:

private:
    void handleInternalEvent(Event ev);
    void handleExternalEvent(Event ev);
    bool sinkInternal(Directive& dv);
    bool sinkExternal(Directive& dv);

};