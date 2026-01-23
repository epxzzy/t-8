#pragma once

#include "./BasicSubModule.hpp"
#include "esp_event_base.h"

struct WiFiConfig;

class WiFiSubModule : public BasicSubModule {

public:
    WiFiSubModule();

    void init() override;
    void start() override;
    void tick() override;
    void stop() override;

    EventType getEventType() override;

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


};