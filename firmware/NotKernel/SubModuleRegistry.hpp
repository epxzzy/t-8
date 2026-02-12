#pragma once

#include "Internal/SubModule/WifiSubMod.hpp"
#include "Registries/BasicRegistry.hpp"
#include "Internal/SubModule/AbstractSubModule.hpp"

typedef Registry<std::string, AbstractSubModule*> reg;

static reg thereg;

reg registerShit(){
    WiFiSubModule* wifiMod = new WiFiSubModule(); 
    thereg.registerItem("wifi", wifiMod);


    /*
    for (int e = 0; e >= sizeof(modulearry)/sizeof(modulearry) ;e++ ) {
        thereg.registerItem("", )
    }
    */
    return thereg;
}

reg acquireSubModuleRegistry(){
    return thereg;
}
