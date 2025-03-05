/*
 * STM32H7Led.cpp
 *
 *  Created on: 09.10.2023
 *      Author: lescher
 */

#include "STM32H7Led.h"

STM32H7Led::STM32H7Led(){
	// TODO Auto-generated constructor stub
}

STM32H7Led::STM32H7Led(GPIO_TypeDef *Port, uint16_t Pin){
	// TODO Auto-generated constructor stub
	STM32H7Led::Port = Port;
	STM32H7Led::Pin = Pin;
}

STM32H7Led::~STM32H7Led(){
	// TODO Auto-generated destructor stub
}
void STM32H7Led::toggleLED(void){
	HAL_GPIO_TogglePin(Port, Pin);
}
