idf_component_register(
    SRCS 
        "old/tasks/logTask.cpp"
        "old/tasks/baseTask.cpp"

        "old/services/systemService.cpp"
        "old/services/managers/SystemServiceManager.cpp"

        "main.cpp"

    INCLUDE_DIRS "./"

    PRIV_REQUIRES
        nvs_flash
        esp_netif
        esp_event
        esp_websocket_client
        log
)

