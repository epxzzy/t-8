#include "WifiSubMod.hpp"
#include "Config.hpp"
#include "Common/data.hpp"
#include "Events/Frame/types.hpp"
#include "esp_netif_types.h"
#include "esp_wifi.h"
#include "esp_netif.h"
#include "esp_event.h"
#include <string.h>

WiFiSubModule::WiFiSubModule()
    : AbstractSubModule() {}

void WiFiSubModule::init() {
    esp_netif_init();
    esp_event_loop_create_default();
    esp_netif_create_default_wifi_sta();

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    esp_wifi_init(&cfg);

    esp_event_handler_register(
        WIFI_EVENT,
        ESP_EVENT_ANY_ID,
        &WiFiSubModule::eventTrampoline,
        this
    );

    esp_event_handler_register(
        IP_EVENT,
        IP_EVENT_STA_GOT_IP,
        &WiFiSubModule::eventTrampoline,
        this
    );
}

void WiFiSubModule::start(){
    wifi_config_t wifi_config{};
    strcpy((char*)wifi_config.sta.ssid, WIFI_SSID);
    strcpy((char*)wifi_config.sta.password, WIFI_PASS);

    esp_wifi_set_mode(WIFI_MODE_STA);
    esp_wifi_set_config(WIFI_IF_STA, &wifi_config);
    esp_wifi_start();
}

void WiFiSubModule::stop(){
    esp_wifi_stop();
    connected = false;
}

void WiFiSubModule::eventTrampoline(
    void* arg,
    esp_event_base_t base,
    int32_t id,
    void* data 
){
    static_cast<WiFiSubModule*>(arg)->handleWifiEvent(base, id, data);
}

void WiFiSubModule::handleWifiEvent(
    esp_event_base_t base,
    int32_t id,
    void* data 
){
    if (base == WIFI_EVENT && id == WIFI_EVENT_STA_START) {
        esp_wifi_connect();
        return;
    } 

    if (base == WIFI_EVENT && id == WIFI_EVENT_STA_DISCONNECTED) {
        connected = false;
        //retryCount++;

        esp_wifi_connect();

        /*
        this->emit(
            Event(
                EventType::WIFI_DISCONNECTED,
                CreateVoidDataPacket(EventType::WIFI_DISCONNECTED)
            )
        );
        */
        return;
    }
    if (base == IP_EVENT && id == IP_EVENT_STA_GOT_IP) {
        connected = true;
        //retryCount = 0;
        
        /*
        this->emit(
        Event(
                EventType::WIFI_CONNECTED,
                CreateVoidDataPacket(EventType::WIFI_CONNECTED)
            )
        );
        */
        //TODO: figure out why these cause a crash
        //^ logs mention interrupts so maybe make a queue and put events in there
        
        return;
    }

}