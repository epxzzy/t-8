#pragma once

#include <stdint.h>
#include <functional>

struct EventData {
	int32_t id;
	void* data;
	size_t data_size;
};