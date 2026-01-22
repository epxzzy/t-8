#pragma once

#include "events/BasicEmitter.hpp"
#include "events/frame/event.hpp"
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

};