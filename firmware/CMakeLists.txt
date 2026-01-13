idf_component_register(
    SRCS 
        "tasks/logTask.cpp"
        "tasks/baseTask.cpp"

        "services/systemService.cpp"
        "services/managers/SystemServiceManager.cpp"

        "main.cpp"

    INCLUDE_DIRS "./"

    PRIV_REQUIRES
        nvs_flash
        esp_netif
        esp_event
        esp_websocket_client
        log
)

