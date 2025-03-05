/*
 * BlinkingLed.h
 *
 *  Created on: 09.10.2023
 *      Author: lescher
 */

#ifndef BLINKINGLED_H_
#define BLINKINGLED_H_

#include "stm32H7xx_hal.h"
#include "NoneBlockSystemTickDelay.h"
#include "STM32H7Led.h"

class BlinkingLed: protected NoneBlockSystemTickDelay, STM32H7Led {
public:
	BlinkingLed();
	virtual ~BlinkingLed();
	BlinkingLed(GPIO_TypeDef *port, uint16_t pin, float_t frequency, uint8_t dutyCycle);
	BlinkingLed(GPIO_TypeDef *port, uint16_t pin);

	void processBlinking(void);

	void setDutyCycle(const uint8_t DutyCycle);
	void setFrequency(const float_t Frequency);


protected:
	float_t Frequency = 1.0;
	uint8_t DutyCycle = 50;

};

#endif /* BLINKINGLED_H_ */
