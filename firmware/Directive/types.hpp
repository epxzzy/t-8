#pragma once

enum DirectiveType: int {
  //submod bound
  
  /*
   * submod(for now) does not need to be commanded.
   * manager is supposed to do that.
   * this list may expand with special "godobject" modules like keyboard for instance.
  */

  //submanager bound

  START_MOD,
  STOP_MOD,
  REGISTER_MOD,
  UNREGISTER_MOD,

  //systemcontroller bound

  TRANSITION, 
  GENERIC_OUTPUT,

  //toolrunner bound
  
	ENTERRUNNER,
  EXITRUNNER,

  //tool bound

  /*
   * tool also(for now) does not need to be commanded.
   * runner/controller is supposed to do that.
   * this list may expand with special "godobject" tools like alarms, rtc, etc
  */

};

enum DirectiveScope: int {
    SUBMODULE,
    SUBMANAGER,
    SYSTEMCONTROLLER,
    TOOLRUNNER,
    TOOL
};
