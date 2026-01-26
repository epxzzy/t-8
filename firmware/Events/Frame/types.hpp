#pragma once

enum EventType: int {
	//tomfuckery, not bound to anything (-1)-100
	//ALL ignores the event scopes
	//unlike 100 and 200 it should be used to return all 
	ALL = -1,
	HB = 1,
	LOG,
	ERROR,
	EXIT,
	CLOSE,

	//SubManager bound, 100-200
	MOD_ALL = 100,
	MOD_REGISTERED,
	MOD_UNREGISTERED,
	MOD_INITED,
	MOD_STARTED,
	MOD_STOPED,
	MOD_SWAPPED,

	//SubModuleBound 200-?
	WIFI_ALL = 200,
    WIFI_CONNECTED,
    WIFI_DISCONNECTED,
    WIFI_RX,
    WIFI_ERROR,
	//TODO: doublecheck and correct these mfs	
	
	// virtual keyboard submodule
	VKBR_ALL = 220,
	VKBR_KEYUP,
	VKBR_KEYDOWN,
	VKBR_ENCODER_PRESS,
	VKBR_ENCODER_TWIST,

	// wifi shit maybe
	

};
