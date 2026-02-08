#pragma once

#include "Events/Frame/types.hpp"
#include <cstddef>
#include <cstdint>
#include <stdint.h>
#include <functional>
#include <string>


//TODO: make data packets its down mother fucking class
//also please for the love of god use some generic fuckery here PLEASS

struct DataPacket {
	int32_t id;
	void* data;
	size_t data_size;
};

//test heartbeat data stuff 
struct HeartBeatData {
	bool alive;
};
constexpr size_t HEARTBEAT_SIZE = sizeof(HeartBeatData);

inline DataPacket CreateHeartBeatDataPacket(bool boo){
	HeartBeatData* dat = new HeartBeatData{boo};
	return DataPacket{EventType::HB, dat, HEARTBEAT_SIZE};
}

inline HeartBeatData ExtractHeartBeatDataPacket(DataPacket dat){
 	return *static_cast<const HeartBeatData*>(dat.data);
} 

//test log data stuff
struct LogData{
	std::string message;
};
constexpr size_t LOG_SIZE = sizeof(LogData);

inline DataPacket CreateLogDataPacket(std::string msg){
	LogData* dat = new LogData{msg};
	return DataPacket{EventType::LOG, dat, LOG_SIZE};
}

inline LogData ExtractLogDataPacket(DataPacket dat){
 	return *static_cast<const LogData*>(dat.data);
} 

//test error data stuff
struct ErrorData{
	std::string msg;
};
constexpr size_t ERROR_SIZE = sizeof(ERROR_SIZE);

inline DataPacket CreateErrorDataPacket(std::string msg){
	ErrorData* dat = new ErrorData{msg};
	return DataPacket{EventType::LOG, dat, ERROR_SIZE};
}

inline ErrorData ExtractErrorDataPacket(DataPacket dat){
 	return *static_cast<const ErrorData*>(dat.data);
} 

//void
inline DataPacket CreateVoidDataPacket(EventType type){
	return DataPacket{type, nullptr, sizeof(DataPacket)};
}


//mod reg data stuff

class BasicSubModule;
//circular dependency hack

struct ModRegData{
	std::string targetName;
	BasicSubModule* module;
};

constexpr size_t REGMOD_SIZE = sizeof(ModRegData);

inline DataPacket CreateModRegDataPacket(std::string msg, BasicSubModule* module){
	ModRegData* dat = new ModRegData{msg, module};
	return DataPacket{8, dat, REGMOD_SIZE};
}

inline ModRegData ExtractModRegDataPacket(DataPacket dat){
 	return *static_cast<const ModRegData*>(dat.data);
} 
