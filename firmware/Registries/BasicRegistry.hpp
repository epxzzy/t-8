#pragma once

#include "Events/Frame/data.hpp"
#include <functional>
#include <string>
#include <unordered_map>
#include <optional>
#include <map>

//TODO: make alla this threadsafe like events
template <typename Key = std::string, typename Value = void*>
class Registry { 

protected:
    typedef std::map<Key, Value> hashmap;
    hashmap map;
public:

    Registry() {};

    virtual ~Registry() {}; 

	void registerItem(const Key& as, Value type){
        this->map.insert_or_assign(as, type);
	};

	void unregisterItem(const Key& as){
		this->map.erase(as);
	};

    Value* acquire(const Key& as){
        typename hashmap::iterator founded =  map.find(as);
        if (founded != map.end()) {
            return &founded->second;
        }
        return 0;
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

