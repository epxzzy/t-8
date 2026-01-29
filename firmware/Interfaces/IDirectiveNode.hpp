#pragma once

#include "Directive/directive.hpp"

class IDirectiveNode {
public:

    virtual DirectiveScope getScope() = 0;
   
    bool canHandle(Directive dv){
        return dv.scope == this->getScope();
    }

};

