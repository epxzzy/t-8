#pragma once

#include "Directive/types.hpp"
#include "Events/Frame/types.hpp"
#include "Interfaces/IDirectiveNode.hpp"
#include "Interfaces/IEmitterNode.hpp"
#include "Internal/SubModule/BasicSubModule.hpp"
#include "Registries/BasicRegistry.hpp"

typedef Registry<std::string, BasicSubModule*> subModReg;

class SubManager : public IEmitterNode, public IDirectiveNode {

public:
  subModReg subManReg;

  EventType getEventType() { return EventType::ALL; }

  DirectiveScope getScope() { return DirectiveScope::SUBMANAGER; }

  std::string registerMod(std::string name, BasicSubModule* submod) {
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
      BasicSubModule* val = it->second;
      val->init();
    };
  };

  void tickMods() {
    for (auto it = this->subManReg.begin(); it != this->subManReg.end(); it++) {
      BasicSubModule* val = it->second;
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
        BasicSubModule* modular = exists->get();
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
        BasicSubModule* modular = exists->get();
        BasicEmitter modularemitter = modular->getEmitter();

        modularemitter.subscribe(
            "SubManager", modular->getEventType(),
            [this](const Event *ev) { this->handleSubModuleEvent(*ev); }
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
      // TODO: ide error, figure out why inheritance is being a bitch
    }
    }
  };
  void handleOrSink(Directive dv);
};
