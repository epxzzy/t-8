#pragma once
#include "../baseService.hpp"

class BaseServiceManager {
public:
    void add(BaseService* s) {
        services[count++] = s;
        this->initServices();
    }

    //todo add methods to add and init specific services

    virtual void initServices() {
        for (int i = 0; i < count; i++) {
            if(services[i]->inited == false){
                services[i]->init();
            }
        }
    }

    virtual void startServices() {
        for (int i = 0; i < count; i++) {
            services[i]->start();
        }
    }
    virtual void stopServices() {
        for (int i = 0; i < count; i++) {
            services[i]->start();
        }
    }

    virtual void tickServices() {
        for (int i = 0; i < count; i++) {
            services[i]->tick();
        }
    }

private:
    static constexpr int MAX_SERVICES = 16;
    BaseService* services[MAX_SERVICES];
    int count = 0;
};
