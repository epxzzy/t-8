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

//test log event stuff
struct ErrorData{
	std::string msg;
};
constexpr size_t ERROR_SIZE = sizeof(ERROR_SIZE);

inline EventData CreateErrorEventData(std::string msg){
	ErrorData* dat = new ErrorData{msg};
	return EventData{EventType::LOG, dat, ERROR_SIZE};
}

inline ErrorData ExtractErrorEventData(EventData dat){
 	return *static_cast<const ErrorData*>(dat.data);
} 

//void
inline EventData CreateVoidEventData(EventType type){
	return EventData{type, nullptr, sizeof(EventData)};
}


