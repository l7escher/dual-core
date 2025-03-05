/*
 * NoneBlockSystemTickDelay.h
 *
 *  Created on: 30.09.2023
 *      Author: lescher
 */

#ifndef NONEBLOCKSYSTEMTICKDELAY_H_
#define NONEBLOCKSYSTEMTICKDELAY_H_


#include "stm32H7xx_hal.h"

class NoneBlockSystemTickDelay{
public:
	NoneBlockSystemTickDelay();
	virtual ~NoneBlockSystemTickDelay();

	void initialize(const uint32_t Delay);

	uint8_t checkExpiration(void);

protected:
	uint32_t Wait = 0;
	uint32_t Tickstart = 0;
};


#endif /* NONEBLOCKSYSTEMTICKDELAY_H_ */
