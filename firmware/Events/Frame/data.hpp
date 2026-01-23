#pragma once

#include "Events/Frame/types.hpp"
#include <cstddef>
#include <cstdint>
#include <stdint.h>
#include <functional>
#include <string>

struct EventData {
	int32_t id;
	void* data;
	size_t data_size;
};

//test heartbeat event stuff 
struct HeartBeatData {
	bool alive;
};
constexpr size_t HEARTBEAT_SIZE = sizeof(HeartBeatData);

inline EventData CreateHeartBeatEventData(bool boo){
	HeartBeatData* dat = new HeartBeatData{boo};
	return EventData{EventType::HB, dat, HEARTBEAT_SIZE};
}

inline HeartBeatData ExtractHeartBeatEventData(EventData dat){
 	return *static_cast<const HeartBeatData*>(dat.data);
} 

//test log event stuff
struct LogData{
	std::string message;
};
constexpr size_t LOG_SIZE = sizeof(LogData);

inline EventData CreateLogEventData(std::string msg){
	LogData* dat = new LogData{msg};
	return EventData{EventType::LOG, dat, LOG_SIZE};
}

inline LogData ExtractLogEventData(EventData dat){
 	return *static_cast<const LogData*>(dat.data);
} 

inline EventData CreateVoidEventData(EventType type){
	return EventData{type, nullptr, sizeof(EventData)};
}


