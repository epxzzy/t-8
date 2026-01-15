#include "systemService.hpp"
#include "nvs_flash.h"
#include "esp_netif.h"
#include "esp_event.h"
#include "old/tasks/logTask.hpp"

static const char* TAG = "SYSTEM_SERVICE";

void SystemService::init() {
    nvs_flash_init();
    esp_netif_init();
    esp_event_loop_create_default();
}

void SystemService::start() {
    static LogTask taskers;
    taskers.start();
    //esp_websocket_client_start(client);
}

void SystemService::tick() {
    //flush queue and shit
}