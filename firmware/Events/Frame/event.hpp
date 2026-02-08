#pragma once

#include <stdint.h>
#include "./types.hpp"
#include "Common/data.hpp"

class Event {
public:
	DataPacket data;
	EventType type;

	Event() = default;

	Event(EventType givenType, DataPacket givenData){
		this->data = givenData;
		this->type = givenType;
	};

	DataPacket getData() const {
		return this->data;
	};
	EventType getType() const {
		return this->type;
	};

};