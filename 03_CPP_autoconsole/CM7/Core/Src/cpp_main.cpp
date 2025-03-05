/*
 * cpp_main.cpp
 *
 *  Created on: Oct 9, 2023
 *      Author: lescher
 */

#include "cpp_main.h"
#include "main.h"
#include <iostream>
#include <cstdint>

//#define ASCII_TAB 	0x09
//#define ASCII_LF 	0x0A
//#define ASCII_CR	0x0D

constexpr char ASCII_TAB = 0x09;
constexpr char ASCII_LF = 0x0A;
constexpr char ASCII_CR = 0x0D;

void cpp_main(){
	while(1){
		//printf("\x1b[2J"); // clear screen
		std::cout<<"\x1b[2J"; // clear screen
		//printf("\033[H"); // move cursor home
		std::cout<<"\033[H"; // move cursor home
		std::cout<<"---------------------------------------------------"<<  ASCII_LF<< ASCII_CR;
		std::cout<<"Counting from 0 to 255: "<< ASCII_LF<< ASCII_CR;

		for(auto counter = 0; counter < 256; counter++){
			std::cout<<"\033[3;0H"; // move cursor
			//printf("\033[3;0H"); // move cursor
			fflush(stdout);
			std::cout<<"counter value:"<< counter << ASCII_LF<< ASCII_CR;
			fflush(stdout);
			HAL_Delay(50);
		}


	}
}
