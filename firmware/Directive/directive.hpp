#pragma once

#include "Common/data.hpp"
#include "Directive/types.hpp"
#include <string>

class Directive {
public:
	DirectiveType type;
	DirectiveScope scope;

    std::string targetName = "";
	//optional, to differentiate between mutliple children
    DataPacket data;
	//optional data
	
	Directive() = default;

	Directive(DirectiveType givenType, DirectiveScope givenScope){
		this->type = givenType;
		this->scope = givenScope;
	};

	Directive(DirectiveType givenType, DirectiveScope givenScope, std::string tarName){
		this->type = givenType;
		this->scope = givenScope;
		this->targetName = tarName;
	};

	Directive(DirectiveType givenType, DirectiveScope givenScope, std::string tarName, DataPacket dat){
		this->type = givenType;
		this->scope = givenScope;
		this->targetName = tarName;
		this->data = dat;
	};

	Directive(DirectiveType givenType, DirectiveScope givenScope, DataPacket dat){
		this->type = givenType;
		this->scope = givenScope;
		this->data = dat;
	};

	DirectiveScope getScope(){
		return this->scope;
	};

	DirectiveType getType(){
		return this->type;
	};

	void* getData(){
		return &this->data;
	};

	std::string getTarget(){
		return this->targetName;
	};
};