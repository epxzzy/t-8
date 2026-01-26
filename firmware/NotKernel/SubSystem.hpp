#pragma once

#include "Directive/directive.hpp"
#include "Directive/types.hpp"
#include "Events/BasicEmitter.hpp"
#include "Events/Frame/event.hpp"
#include "Internal/SubManager/SubManager.hpp"

class SubSystem {

public:
    SubManager submanager;

    void init();
    void tick();

protected:

private:
    void handleInternalEvent(Event ev);
    void handleExternalEvent(Event ev);
    void sinkInternal(Directive dv);
    void sinkExternal(Directive dv);

};