#pragma once

enum EventType: int {
	//tomfuckery, not bound to anything (-1)-100
	ALL = -1,
	HB = 1,
	LOG,
	EXIT,
	CLOSE,

	//SubManager bound, 100-200
	SUBMODALL = 100,
	SUBMODREGISTER,
	SUBMODUNREGISTER,
	SUBMODINIT,
	SUBMODSTART,
	SUBMODSTOP,
	SUBMODSWAP,

	//SubModuleBound 200-?
	
	// virtual keyboard submodule
	VKBR_ALL = 200,
	VKBR_KEYUP,
	VKBR_KEYDOWN,
	VKBR_ENCODER_PRESS,
	VKBR_ENCODER_TWIST,
	
};
