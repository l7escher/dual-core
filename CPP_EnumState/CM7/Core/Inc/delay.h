/*
 * delay.h
 *
 *  Created on: 25.09.2023
 *      Author: lescher
 */

#include <stdint.h>
#include "stm32h7xx_hal.h"

#ifndef INC_DELAY_H_
#define INC_DELAY_H_



#ifdef __cplusplus
extern "C" {
#endif


void Delay_Init(uint32_t *tickstart, uint32_t *wait);

uint8_t My_Nonblocking_Delay(uint32_t tickstart, uint32_t wait);


#ifdef __cplusplus
}
#endif



#endif /* INC_DELAY_H_ */
