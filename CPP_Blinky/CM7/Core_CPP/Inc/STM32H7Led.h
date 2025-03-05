/*
 * STM32H7Led.h
 *
 *  Created on: 30.09.2023
 *      Author: lescher
 */

#ifndef STM32H7LED_H_
#define STM32H7LED_H_

#include "stm32H7xx_hal.h"

class STM32H7Led{
public:
	STM32H7Led();
	virtual ~STM32H7Led();

	STM32H7Led(GPIO_TypeDef *port, uint16_t pin);

	void toggleLED(void);

protected:
	GPIO_TypeDef *Port;
	uint16_t Pin;
};




#endif /* STM32H7LED_H_ */
