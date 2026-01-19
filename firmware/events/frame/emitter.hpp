#pragma once

#include <functional>
#include <string>
#include <unordered_map>
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "event.hpp"
#include "./types.hpp"

typedef std::function<void(const Event *event)> ListenerCallback;
typedef std::unordered_map<std::string, ListenerCallback> SubscriberMap;
typedef std::unordered_map<EventType, SubscriberMap> ListenersMap;

class EventEmitter {
public:

	EventEmitter() {
        mutex = xSemaphoreCreateMutex();
        if (mutex == nullptr) {
        }
    }

    ~EventEmitter() {
        if (mutex != nullptr) {
            vSemaphoreDelete(mutex);
        }
    }

	void subscribeAll(std::string subscriberName, ListenerCallback callback){
		xSemaphoreTake(mutex, portMAX_DELAY);
		this->Listeners[EventType::ALL][subscriberName] = callback;
		xSemaphoreGive(mutex);

	};

	void subscribe(std::string subscriberName, EventType type, ListenerCallback callback){
		xSemaphoreTake(mutex, portMAX_DELAY);
		this->Listeners[type][subscriberName] = callback;
		xSemaphoreGive(mutex);
	};

	void unsubscribeAll(std::string subscriberName){
		xSemaphoreTake(mutex, portMAX_DELAY);
		this->Listeners[EventType::ALL].erase(subscriberName);
		xSemaphoreGive(mutex);
	};

	void unsubscribe(std::string subscriberName, EventType type){
		xSemaphoreTake(mutex, portMAX_DELAY);
		this->Listeners[type].erase(subscriberName);
		xSemaphoreGive(mutex);
	};


	void emit(Event event){
		xSemaphoreTake(mutex, portMAX_DELAY);

		EventType typer = event.getType();

		//call subscribers	
		for(auto pair: (Listeners.find(typer))->second){
			pair.second(&event);	
		}

		//call all
		//nullcheck
		if(Listeners.count(EventType::ALL) != 0){
			for(auto pair: (Listeners.find(EventType::ALL))->second){
				pair.second(&event);	
			}
		}	

		xSemaphoreGive(mutex);
		delete static_cast<char*>(event.data.data);
	};

private:
	ListenersMap Listeners;
	SemaphoreHandle_t mutex = nullptr;
};
