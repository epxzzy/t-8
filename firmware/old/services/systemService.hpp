#pragma once

#include "baseService.hpp"
#include <cstdint>

class SystemService final : public BaseService {
public:
    const char* name() const override { return "WebSocketService"; }

    void init() override;
    void start() override;
    void tick() override;

private:
    bool connected = false;

    static void event_handler(
        void* arg,
        int32_t event_id,
        void* event_data
    );
};
