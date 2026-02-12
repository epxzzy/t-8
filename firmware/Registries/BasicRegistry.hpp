#pragma once

#include "Common/data.hpp"
#include "Internal/SubModule/AbstractSubModule.hpp"
#include <functional>
#include <string>
#include <unordered_map>
#include <optional>
#include <map>

template <typename Key = std::string, typename Value = void*>
class Registry { 

protected:
    typedef std::map<Key, Value> hashmap;
    hashmap map;
    SemaphoreHandle_t mutex = nullptr;
public:

	Registry() {
        mutex = xSemaphoreCreateMutex();
        if (mutex == nullptr) {
        }
    }

    virtual ~Registry() {
        if (mutex != nullptr) {
            vSemaphoreDelete(mutex);
        }
    }


	void registerItem(const Key& as, Value type){
		xSemaphoreTake(mutex, portMAX_DELAY);
        this->map.insert_or_assign(as, type);
		xSemaphoreGive(mutex);
	};

	void unregisterItem(const Key& as){
		xSemaphoreTake(mutex, portMAX_DELAY);
		this->map.erase(as);
		xSemaphoreGive(mutex);
	};

    std::optional<std::reference_wrapper<Value>> acquire(Key& as){
		xSemaphoreTake(mutex, portMAX_DELAY);
        typename hashmap::iterator founded = map.find(as.data());
        if (founded != map.end()) {
            return std::ref(founded->second);
        }
        return std::nullopt;

		xSemaphoreGive(mutex);
    };

    //typedef typename evdatahashmap::iterator iterator;
    typedef typename hashmap::iterator iterator;

    iterator begin(){
        return map.begin();
    }

    iterator end(){
        return map.end();
    }

    size_t size(){
        return map.size(); 
    }

    bool empty(){
        return map.empty();
    }

};

