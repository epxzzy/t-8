#pragma once

#include "baseService.hpp"
#include "esp_websocket_client.h"

class WSService: public BaseService {
public:
    const char* name() const { return "WebSocketService"; }

    void init();
    void start();
    void tick();

private:
    esp_websocket_client_handle_t client = nullptr;
    bool connected = false;

    static void event_handler(
        void* arg,
        esp_event_base_t base,
        int32_t event_id,
        void* event_data
    );
};
