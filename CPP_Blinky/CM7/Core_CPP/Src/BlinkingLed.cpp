/*
 * BlinkingLed.cpp
 *
 *  Created on: 09.10.2023
 *      Author: lescher
 */

#include "BlinkingLed.h"

BlinkingLed::BlinkingLed() {
	// TODO Auto-generated constructor stub
}

BlinkingLed::BlinkingLed(GPIO_TypeDef *Port, uint16_t Pin){
	BlinkingLed::Port = Port;
	BlinkingLed::Pin = Pin;
}

BlinkingLed::BlinkingLed(GPIO_TypeDef *Port, uint16_t Pin, float_t frequency, uint8_t dutyCycle){
	BlinkingLed::Port = Port;
	BlinkingLed::Pin = Pin;
	BlinkingLed::Frequency = frequency;
	BlinkingLed::DutyCycle = dutyCycle;
}

BlinkingLed::~BlinkingLed() {
	// TODO Auto-generated destructor stub
}

void BlinkingLed::setDutyCycle(const uint8_t dutyCycle){
	BlinkingLed::DutyCycle = dutyCycle;
}

void BlinkingLed::setFrequency(const float_t frequency){
	BlinkingLed::Frequency = frequency;
}

void BlinkingLed::processBlinking(){
	if(BlinkingLed::checkExpiration()){
		BlinkingLed::initialize(1/Frequency*1000);
		BlinkingLed::toggleLED();
	}
}
