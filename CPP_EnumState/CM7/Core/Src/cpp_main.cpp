/*
 * cpp_main.cpp
 *
 *  Created on: Sep 25, 2023
 *      Author: lescher
 */

#include "cpp_main.h"
#include "main.h"
#include "delay.h"


enum class states_led1{INIT, BLINK_1HZ, BLINK_3HZ};
enum class states_led2{INIT, BLINK_1HZ, BLINK_2HZ};

enum states_led1 statemachine1 = states_led1::INIT;
enum states_led2 statemachine2 = states_led2::INIT;

uint32_t DelayLED1 = 0;
uint32_t DelayLED2 = 0;
uint32_t tickstartLED1 = 0;
uint32_t tickstartLED2 = 0;


//state machine 1
void execStatemachine1(){
	uint8_t count;

	switch(statemachine1){
	case states_led1::INIT:
		count = 0;
		DelayLED1 = 1000;
		tickstartLED1 = 0;
		Delay_Init(&tickstartLED1, &DelayLED1);
		statemachine1 = states_led1::BLINK_1HZ;
		break;

	case states_led1::BLINK_1HZ:
		if(My_Nonblocking_Delay(tickstartLED1, DelayLED1)){
			Delay_Init(&tickstartLED1, &DelayLED1);
			HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
			count++;
		}
		if(count>10){
			count = 0;
			DelayLED1=333;
			Delay_Init(&tickstartLED1, &DelayLED1);
			statemachine1 = states_led1::BLINK_3HZ;
		}
		break;

	case states_led1::BLINK_3HZ:
		if(My_Nonblocking_Delay(tickstartLED1, DelayLED1)){
			Delay_Init(&tickstartLED1, &DelayLED1);
			HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
			count++;
		}
		if(count>10){
			count = 0;
			DelayLED1 = 1000;
			Delay_Init(&tickstartLED1, &DelayLED1);
			statemachine1 = states_led1::BLINK_1HZ;
		}
		break;

	default:
		break;
	}
}

//state machine 2
void execStatemachine2(){
	uint8_t count;

	switch(statemachine2){
	case states_led2::INIT:
		count = 0;
		DelayLED2 = 1000;
		tickstartLED2 = 0;
		Delay_Init(&tickstartLED2, &DelayLED2);
		statemachine2 = states_led2::BLINK_1HZ;
		break;

	case states_led2::BLINK_1HZ:
		if(My_Nonblocking_Delay(tickstartLED2, DelayLED2)){
			Delay_Init(&tickstartLED2, &DelayLED2);
			HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
			count++;
		}
		if(count>10){
			count = 0;
			DelayLED2=500;
			Delay_Init(&tickstartLED2, &DelayLED2);
			statemachine2 = states_led2::BLINK_2HZ;
		}
		break;

	case states_led2::BLINK_2HZ:
		if(My_Nonblocking_Delay(tickstartLED2, DelayLED2)){
			Delay_Init(&tickstartLED2, &DelayLED2);
			HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
			count++;
		}
		if(count>10){
			count = 0;
			DelayLED2 = 1000;
			Delay_Init(&tickstartLED2, &DelayLED2);
			statemachine2 = states_led2::BLINK_1HZ;
		}
		break;

	default:
		break;
	}
}




void cpp_main(){
	while(1){
		execStatemachine1();
		execStatemachine2();


	}
}
