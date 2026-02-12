#pragma once

#include "Common/data.hpp"
#include "Directive/types.hpp"
#include "Events/Frame/types.hpp"
#include "Interfaces/IDirectiveNode.hpp"
#include "Interfaces/IEmitterNode.hpp"
#include "Internal/SubModule/AbstractSubModule.hpp"
#include "Registries/BasicRegistry.hpp"

typedef Registry<std::string, AbstractSubModule*> subModReg;

class SubManager : public IEmitterNode, public IDirectiveNode<SubManager> {

public:
  using IDirectiveNode<SubManager>::registerHandler;

  subModReg subManReg;

  EventType getEventType() { return EventType::ALL; }

  DirectiveScope getScope() { return DirectiveScope::SUBMANAGER; }

  SubManager(){

    IDirectiveNode<SubManager>::registerHandler(
      DirectiveType::START_MOD,
      [](SubManager& node, const Directive& dv){
        auto& self = static_cast<SubManager&>(node);
        
        self.start(dv.targetName.data());
        return true;
      }
    ); 

    IDirectiveNode<SubManager>::registerHandler(
      DirectiveType::STOP_MOD,
      [](SubManager& node, const Directive& dv){
        auto& self = static_cast<SubManager&>(node);
        
        self.stop(dv.targetName.data());
        return true;
      }
    ); 

    IDirectiveNode<SubManager>::registerHandler(
      DirectiveType::REGISTER_MOD,
      [](SubManager& node, const Directive& dv){
        auto& self = static_cast<SubManager&>(node);
        
        self.registerMod(dv.targetName.data(), ExtractModRegDataPacket(dv.data).module);
        return true;
      }
    ); 

    IDirectiveNode<SubManager>::registerHandler(
      DirectiveType::UNREGISTER_MOD,
      [](SubManager& node, const Directive& dv){
        auto& self = static_cast<SubManager&>(node);
        
        self.unregisterMod(dv.targetName.data());
        return true;
      }
    ); 

  }
  
  std::string registerMod(std::string name, AbstractSubModule* submod) {
    this->subManReg.registerItem(name, submod);
    return name;
  };

  std::string unregisterMod(std::string name) {
    this->subManReg.unregisterItem(name);
    return name;
  };

  subModReg acquireRegistry() { return this->subManReg; }

  void initMods() {
    for (auto it = this->subManReg.begin(); it != this->subManReg.end(); it++) {
      AbstractSubModule* val = it->second;
      val->init();
    };
  };

  void tickMods() {
    for (auto it = this->subManReg.begin(); it != this->subManReg.end(); it++) {
      AbstractSubModule* val = it->second;
      val->tick();
    }
  };

  void startMods() {
    for (auto it = this->subManReg.begin(); it != this->subManReg.end(); it++) {
      this->start(it->first);
    }
  };

  void stopMods() {
    for (auto it = this->subManReg.begin(); it != this->subManReg.end(); it++) {
      this->stop(it->first);
    }
  };

  void start(std::string name) {
    auto exists = this->subManReg.acquire(name);
    if (exists) {
        AbstractSubModule* modular = exists->get();
        BasicEmitter modularemitter = modular->getEmitter();

        modularemitter.subscribe(
            "SubManager", modular->getEventType(),
            [this](const Event *ev) { this->handleSubModuleEvent(*ev); }
        );

        modular->start();
    }
  };

  void stop(std::string name) {
    auto exists = this->subManReg.acquire(name);
    if (exists) {
        AbstractSubModule* modular = exists->get();
        BasicEmitter modularemitter = modular->getEmitter();

        modularemitter.unsubscribe(
            "SubManager", modular->getEventType()
        );

        modular->stop();            
    }
  };

protected:
private:
  void handleSubModuleEvent(const Event ev) {
    // TODO: create and bind events to start stop and else.
    // so the tools can fuckin do shit
    switch (ev.type) {
      case EventType::LOG: {
        // any specific case to be handled here
      } break;
      default: {
        this->emit(ev);
        /*
         * Cannot initialize object parameter of type 'IEmitterNode' with an expression of type 'SubManager'
        */
        //ide error, lsp issue
      }
    }
  };

  bool additionalHandling(const Directive& dv){
    //TODO: do child selecting via directive data specifically set for multi-child parents
    return false;
  }
  void handleOrSink(Directive dv);
};
