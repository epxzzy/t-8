idf_component_register(
    SRCS 
        "main.cpp"
        
        "Common/data.hpp"
        "Events/Frame/emitter.hpp"
        "Events/Frame/event.hpp"
        "Events/Frame/types.hpp"

        "Events/BasicEmitter.hpp"


        "Directive/directive.hpp"
        "Directive/types.hpp"

        "External/SystemController.cpp"
        "External/SystemController.hpp"

        "Interfaces/IDirectiveNode.hpp"
        "Interfaces/IEmitterNode.hpp"

        "Internal/SubManager/SubManager.hpp"
        "Internal/SubModule/BasicSubModule.hpp"
        "Internal/SubModule/WifiSubMod.cpp"
        "Internal/SubModule/WifiSubMod.hpp"

        "NotKernel/SubModuleRegistry.hpp"
        "NotKernel/SubSystem.cpp"
        "NotKernel/SubSystem.hpp"

        "Registries/BasicRegistry.hpp"

    INCLUDE_DIRS "./"

    PRIV_REQUIRES
        nvs_flash
        esp_netif
        esp_event
        esp_websocket_client
        log
        esp_wifi 
)

