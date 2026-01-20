#pragma once

enum EventType: int {
	ALL = -1,
	HB = 1,
	LOG = 2,
	EXIT,
	CLOSE,

	//submodules 100-200
	SUBMODALL = 100,
	SUBMODREGISTER,
	SUBMODUNREGISTER,
	SUBMODINIT,
	SUBMODSTART,
	SUBMODSTOP,
	SUBMODSWAP,

	//specific submodule stuff 200-300 sectioned into like 20 or something max
	VKBR_ALL = 200,
	VKBR_KEYUP,
	VKBR_KEYDOWN,
	VKBR_ENCODER_PRESS,
	VKBR_ENCODER_TWIST,
	
};
