/*
 * cpp_main.cpp
 *
 *  Created on: Sep 25, 2023
 *      Author: lescher
 */

#include "cpp_main.h"
#include "main.h"

#include "NoneBlockSystemTickDelay.h"
#include "STM32H7Led.h"
#include "BlinkingLed.h"

void cpp_main(){

	BlinkingLed Led1(LD1_GPIO_Port, LD1_Pin);
	Led1.setFrequency(0.5);

	BlinkingLed Led2{LD2_GPIO_Port, LD2_Pin};
	Led2.setFrequency(1);

	BlinkingLed Led3{LD3_GPIO_Port, LD3_Pin};
	Led3.setFrequency(2);

	//BlinkingLed Led2(LD2_GPIO_Port, LD2_Pin, frequency = 2, dutyCycle = 0);

	while(1){
		Led1.processBlinking();
		Led2.processBlinking();
		Led3.processBlinking();

		}

		//HAL_Delay(500);


}
