/*
 * delay.c
 *
 *  Created on: 25.09.2023
 *      Author: lescher
 */

#include "delay.h"

void Delay_Init(uint32_t *tickstart, uint32_t *Delay) {
	*tickstart = HAL_GetTick();

	if (*Delay < HAL_MAX_DELAY) {
		*Delay += (uint32_t) (uwTickFreq);
	}
}

/*
 *return value = 0: delay ist not finished
 *return value = 255: delay finished
 */
uint8_t My_Nonblocking_Delay(uint32_t tickstart, uint32_t wait) {
	if ((HAL_GetTick() - tickstart) < wait) {
		return 0;
	} else {
		return 255;
	}
}

//	   void HAL_Delay(uint32_t Delay)
//	  {
//	    uint32_t tickstart = HAL_GetTick();
//	    uint32_t wait = Delay;
//
//	    /* Add a freq to guarantee minimum wait */
//	    if (wait < HAL_MAX_DELAY)
//	    {
//	      wait += (uint32_t)(uwTickFreq);
//	    }
//
//	    while ((HAL_GetTick() - tickstart) < wait)
//	    {
//	    }
//	  }
