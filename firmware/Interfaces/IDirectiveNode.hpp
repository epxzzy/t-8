#pragma once

#include "Directive/directive.hpp"
#include <functional>
#include <map>

template <typename T>
class IDirectiveNode {
public:
    using Handler = std::function<bool(T&, const Directive&)>;

    virtual ~IDirectiveNode() = default;

    virtual DirectiveScope getScope() = 0;

    virtual bool additionalHandling(const Directive& dv){
        return false;
    }
   
    bool handle(Directive& dv){
        if(!canHandle(dv)){
            return additionalHandling(dv);
        }

        auto& table = dispatchTable();

        auto it = table.find(dv.type);

        if(it != table.end()){ 
            if(it->second(static_cast<T&>(*this), dv)){
                return true;
            }
        }

        return false;
    }

    bool canHandle(Directive& dv){
        return dv.scope == this->getScope();
    }

    static void registerHandler(DirectiveType type, Handler h){
        dispatchTable()[type] = std::move(h);
    }

private:
    static std::map<DirectiveType, Handler>& dispatchTable(){
        static std::map<DirectiveType, Handler> table; 
        return table;
    };
};
