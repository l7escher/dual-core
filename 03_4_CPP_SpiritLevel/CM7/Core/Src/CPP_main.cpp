/*
 * CPP_main.cpp
 *
 *  Created on: Feb 5, 2024
 *      Author: lescher
 *
 */

#include "CPP_main.h"
#include "main.h"
#include <iostream>
#include <cstdint>

#include "IKS01A3Motion.h"
#include "SpiritLevelSinglAxis3LED.h"


constexpr char ASCII_TAB=  0x09;
constexpr char ASCII_LF  =  0x0A;
constexpr char ASCII_CR  =  0x0D;

SpiritLevelSinglAxis3LED Level;

void cpp_main(){

//while (1)
//  {
//  //printf("\x1b[2J"); // clear screen
//  std::cout<<"\x1b[2J"; // clear screen
//  //printf("\033[H"); // move cursor home
//  std::cout<<"\033[H"; // move cursor home
//  std::cout<<"---------------------------------------------------"<<  ASCII_LF<< ASCII_CR;
//  std::cout<<"Counting from 0 to 255: "<< ASCII_LF<< ASCII_CR;
//
//  for(auto counter=0;counter<256;counter++){
//    std::cout<<"\033[3;0H"; // move cursor
//    //printf("\033[3;0H"); // move cursor
//    fflush(stdout);
//    std::cout<<"counter value:"<< counter << ASCII_LF<< ASCII_CR;
//    fflush(stdout);
//    HAL_Delay(50);
//    }
//  }

	Level.init();
	while(1){
		if(HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin)){
			Level.setZero();
		}

		Level.updateValues();
		Level.show();
		HAL_Delay(100);
	}





}


