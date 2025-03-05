/*
 * SpiritLevelSinglAxis3LED.h
 *
 *  Created on: 05.02.2024
 *      Author: muaha
 */

#ifndef SRC_SPIRITLEVELSINGLAXIS3LED_H_
#define SRC_SPIRITLEVELSINGLAXIS3LED_H_

#include "STM32H7led.h"
#include "AccGyroSensor.h"

class SpiritLevelSinglAxis3LED {
private:
	const int32_t Threshold = 200;

	STM32H7_led LedNegAngle;
	STM32H7_led LedPosAngle;
	STM32H7_led LedBalanced;

	AccGyroSensor AccGyro;
public:
	SpiritLevelSinglAxis3LED();
	virtual ~SpiritLevelSinglAxis3LED();

	void init(void);
	void updateValues(void);
	void show(void);
	void setZero(void);
};

#endif /* SRC_SPIRITLEVELSINGLAXIS3LED_H_ */
