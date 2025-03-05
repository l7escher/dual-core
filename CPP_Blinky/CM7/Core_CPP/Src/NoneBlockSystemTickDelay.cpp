/*
 * NoneBlockSystemTickDelay.cpp
 *
 *  Created on: 30.09.2023
 *      Author: lescher
 */

#include "NoneBlockSystemTickDelay.h"

NoneBlockSystemTickDelay::NoneBlockSystemTickDelay(){
	// TODO Auto-generated constructor stub
}

NoneBlockSystemTickDelay::~NoneBlockSystemTickDelay(){
	// TODO Auto-generated destructor stub
}

void NoneBlockSystemTickDelay::initialize(const uint32_t Delay){
	Wait = Delay;
	Tickstart = HAL_GetTick();

	if(Wait < HAL_MAX_DELAY){
		Wait += (uint32_t)(uwTickFreq);
	}
}

uint8_t NoneBlockSystemTickDelay::checkExpiration(void){
	if(Wait != 0){
		if((HAL_GetTick() - Tickstart) < Wait) return 0;
		else {
			Wait = 0;
			return 255;
		}
	} else return 255;
}
