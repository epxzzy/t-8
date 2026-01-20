#include <cstdio>
#include <stdio.h>
#include "events/frame/data.hpp"
#include "events/frame/event.hpp"
#include "events/frame/emitter.hpp"
#include "events/frame/types.hpp"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "registries/basicregistry.hpp"

//#include "old/tasks/logTask.hpp"
//#include "old/services/systemService.hpp"
//#include "old/services/managers/SystemServiceManager.cpp"

extern "C" void app_main(void);

void hello_task(void* arg) {
  while (true) {
    printf("sup bitches\n");
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}

extern "C" void app_main(void) {

  typedef Registry<std::string, int> intreg; 
  intreg reg;
  reg.registeritem("firstnamer", 0);
  reg.registeritem("seconder", 1);
  reg.registeritem("thirter", 2);
  reg.registeritem("foruder", 3);
  reg.registeritem("vidth", 4);

  for (auto it = reg.begin();it != reg.end() ; it++) {
    std::string str = it->first;
    int val = it->second; 
    printf("sting: %s, imt: %d\n", str.data(), val);
  }

  
// #9166e4c "i am so stupid, working example"
/*
  EventEmitter emitter;          

  emitter.subscribe("heartbeat subscriber", EventType::HB, 
    [](const Event* ev) {
      HeartBeatData hbdat = ExtractHeartBeatEventData(ev->data);
      printf("heartbeat: %s\n", 
        hbdat.alive ?
          "heartbeat: mfs still alive" :
          "heartbeat: mfs dead lmao"
        );
    }
  );

  emitter.subscribe("log subscriber", EventType::LOG, 
    [](const Event* ev) {
      LogData logdat = ExtractLogEventData(ev->data);
      printf("log: %s\n", logdat.message.data());
      // outputs "log: ��" for whatever reason
    }
  );

  for (int i = 0; ;i++){
    Event eventtoPoste;
    if (i % 2 != 0){
      const std::string msg[] = {
        "message one",
        "message two",
        "message tree",
        "message idk i lost count"
      };
      int selection = (i/2) % 4;
      eventtoPoste = Event(
        EventType::LOG,
        CreateLogEventData(msg[selection])
      );
    }
    else {
      bool boo = (i/2) % 2 == 0 ? true: false;
      eventtoPoste = Event(
        EventType::HB,
        CreateHeartBeatEventData(boo)
      );
    }
    emitter.emit(eventtoPoste);
    vTaskDelay(pdMS_TO_TICKS(1000));
  }

*/

// #a3e1582 "half assed service attempt ill redo the system anyways"
/*   
    static SystemServiceManager services;
    static SystemService sys;

    services.add(&sys);

    services.initServices();
    services.startServices();

    while (true) {
        services.tickServices();
        vTaskDelay(pdMS_TO_TICKS(10)); // cooperative “parallelism”
    }
    */

// #608d23e "asserting dominance"
/*
    xTaskCreate(
        hello_task,      
        "hello_task",   
        2048,            
        //stack size in bytes
        nullptr,         
        //params
        1,              
        //priority
        nullptr          
        //task handle
    );
   */
}

