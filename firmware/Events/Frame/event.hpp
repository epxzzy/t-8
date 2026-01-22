#pragma once

#include <stdint.h>
#include "./types.hpp"
#include "./data.hpp"

class Event {
public:
	EventData data;
	EventType type;

	Event() = default;

	Event(EventType givenType, EventData givenData){
		this->data = givenData;
		this->type = givenType;
	};

	EventData getData(){
		return this->data;
	};
	EventType getType(){
		return this->type;
	};

};