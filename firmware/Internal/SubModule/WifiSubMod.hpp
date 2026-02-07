#pragma once

#include "./BasicSubModule.hpp"
#include "Interfaces/IEmitterNode.hpp"
#include "esp_event_base.h"

struct WiFiConfig;

class WiFiSubModule : public BasicSubModule {

public:
    WiFiSubModule();

    void init() override;
    void start() override;
    void tick() override {};
    //empty override so things dont fuck themselves
    void stop() override;

    EventType getEventType() override {
        return EventType::WIFI_ALL;
    }

    void emit(Event ev) override {
        (this->getEmitter()).emit(ev);
    } 

private:
    bool connected = false;
    int retryCount = 0;

    static void eventTrampoline(
        void* arg,
        esp_event_base_t base,
        int32_t id,
        void* data
    );

    void handleWifiEvent(
        esp_event_base_t base,
        int32_t id,
        void* data
    );
    void handleSubModuleEvent(const Event ev)  {};

};
