/*
 * cpp_main.cpp
 *
 *  Created on: Sep 25, 2023
 *      Author: lescher
 */

#include "cpp_main.h"
#include "main.h"
#include <algorithm>

template <typename values>
values calcAVGofField(values *pointerOnField, uint32_t numElements){
	double Average;

	for(uint32_t i = 0; i < numElements; i++){
		Average = Average + (double)pointerOnField[i];
	}
	Average = Average /= (double)numElements;

	return (values)Average;
}


void cpp_main(){

	int16_t array[6] = {232,4512,4551,20187,888,15124};
	int16_t Average = 0;

	Average = calcAVGofField(&array[0], 6);

	while(1){

		std::sort(&array[3], &array[6]);
		Average = calcAVGofField(&array[0], 6);


		}

}
