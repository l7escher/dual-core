/*
 * SpiritLevelSinglAxis3LED.cpp
 *
 *  Created on: 05.02.2024
 *      Author: muaha
 */

#include <SpiritLevelSinglAxis3LED.h>
#include "main.h"
#include <iostream>

constexpr char ASCII_TAB=  0x09;
constexpr char ASCII_LF  =  0x0A;
constexpr char ASCII_CR  =  0x0D;

SpiritLevelSinglAxis3LED::SpiritLevelSinglAxis3LED() {
	// TODO Auto-generated constructor stub

}

SpiritLevelSinglAxis3LED::~SpiritLevelSinglAxis3LED() {
	// TODO Auto-generated destructor stub
}

void SpiritLevelSinglAxis3LED::init(void) {
	AccGyro.initSensor();
	LedBalanced.init(LD2_GPIO_Port, LD2_Pin);
	LedNegAngle.init(LD1_GPIO_Port, LD1_Pin);
	LedPosAngle.init(LD3_GPIO_Port, LD3_Pin);
}

void SpiritLevelSinglAxis3LED::updateValues(void) {
	AccGyro.updateValues();
}

void SpiritLevelSinglAxis3LED::show(void) {
	int32_t Accx = 0;
	int32_t Accy = 0;
	int32_t Accz = 0;

	AccGyro.Accelero.getAVGValues(&Accx, &Accy, &Accz);

	if(Accy < Threshold * (-1)){
		LedBalanced.unsetLED();
		LedNegAngle.setLED();
		LedPosAngle.unsetLED();
	} else if(Accy > Threshold){
		LedBalanced.unsetLED();
		LedNegAngle.unsetLED();
		LedPosAngle.setLED();
	} else {
		LedBalanced.setLED();
		LedNegAngle.unsetLED();
		LedPosAngle.unsetLED();
	}

	std::cout << "X-Axis = " << Accx << ASCII_TAB;
	fflush(stdout);

	std::cout << "Y-Axis = " << Accy << ASCII_TAB;
	fflush(stdout);

	std::cout << "Z-Axis = " << Accz << ASCII_TAB;
	fflush(stdout);

	std::cout << ASCII_LF << ASCII_CR;
	fflush(stdout);

}

void SpiritLevelSinglAxis3LED::setZero(void) {
	AccGyro.setZero();
}
