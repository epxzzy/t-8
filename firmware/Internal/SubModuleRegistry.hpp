#pragma once

#include "Registries/BasicRegistry.hpp"
#include "Internal/SubModule/BasicSubModule.hpp"

typedef Registry<std::string, BasicSubModule> reg;

static reg thereg;

reg registerShit(){
    
    thereg.registerItem("basic", BasicSubModule());


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