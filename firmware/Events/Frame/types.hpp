#pragma once

enum EventType: int {
	//tomfuckery, not bound to anything (-1)-100
	//ALL ignores the event scopes
	//unlike 100 and 200 it should be used to return all 
	ALL = -1,
	HB = 1,
	LOG,
	EXIT,
	CLOSE,

	//SubManager bound, 100-200
	MODALL = 100,
	MODREGISTERED,
	MODUNREGISTERED,
	MODINITED,
	MODSTARTED,
	MODSTOPED,
	MODSWAPPED,

	//SubModuleBound 200-?
	
	// virtual keyboard submodule
	VKBR_ALL = 200,
	VKBR_KEYUP,
	VKBR_KEYDOWN,
	VKBR_ENCODER_PRESS,
	VKBR_ENCODER_TWIST,

	// wifi shit maybe
	

};
