#pragma once

#include "./AbstractSubModule.hpp"
#include "Interfaces/IEmitterNode.hpp"
#include "esp_event_base.h"
#include <cstdio>

struct WiFiConfig;

class WiFiSubModule : public AbstractSubModule {

public:
    WiFiSubModule();

    void init() override;
    void start() override;
    void tick() override {
    };
    bool isConnected() const { return connected; }
    //empty override so things dont fuck themselves
    void stop() override;

    EventType getEventType() override {
        return EventType::WIFI_ALL;
    }

    void emit(Event ev) override {
        (this->getEmitter()).emit(ev);
    } 

    bool handle(Directive* dv) override {
        return false;
    }

private:
    volatile bool connected = false;
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
