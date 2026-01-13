#pragma once

class BaseService {
public:
    virtual const char* name() const = 0;
    bool inited = false;

    virtual void init() {
        this->inited = true;
    }
    virtual void start() {}
    virtual void stop() {}
    virtual void tick() {}
    virtual void clean(){}

    BaseService() = default;
    ~BaseService() = default;
};
