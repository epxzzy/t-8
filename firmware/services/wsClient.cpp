#include "wsClient.hpp"
#include "esp_log.h"

static const char* TAG = "WS_SERVICE";

void WSService::init() {
    esp_websocket_client_config_t cfg = {};
    cfg.uri = "ws://echo.websocket.events"; // Wokwi-safe

    client = esp_websocket_client_init(&cfg);

    esp_websocket_register_events(
        client,
        WEBSOCKET_EVENT_ANY,
        &WSService::event_handler,
        this
    );
}

void WSService::start() {
    esp_websocket_client_start(client);
}

void WSService::tick() {

}

void WSService::event_handler(
    void* arg,
    esp_event_base_t,
    int32_t event_id,
    void* event_data
) {
    auto* self = static_cast<WSService*>(arg);
    auto* data = static_cast<esp_websocket_event_data_t*>(event_data);

    switch (event_id) {
        case WEBSOCKET_EVENT_CONNECTED:
            self->connected = true;
            ESP_LOGI(TAG, "connected");
            break;

        case WEBSOCKET_EVENT_DATA:
            ESP_LOGI(
                TAG,
                "rx (%d): %.*s",
                data->op_code,
                data->data_len,
                (char*)data->data_ptr
            );
            break;

        case WEBSOCKET_EVENT_DISCONNECTED:
            self->connected = false;
            ESP_LOGW(TAG, "disconnected");
            break;

        case WEBSOCKET_EVENT_ERROR:
            ESP_LOGE(TAG, "error");
            break;
    }
}
