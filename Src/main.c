/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>



int main(void)
{
    /* Loop forever */
	uint32_t volatile *pClockCtrlReg = (uint32_t*)0x40023830;
	uint32_t volatile *pPortDModeReg = (uint32_t*)0x40020C00;
	uint32_t volatile *pPortDOutReg = (uint32_t*)0x40020C14;

	uint32_t volatile *pPortAModeReg = (uint32_t*)0x40020000;
	uint32_t volatile *pPortAInReg = (uint32_t*)0x40020010;


    *pClockCtrlReg |= (1<<3);
    *pClockCtrlReg |= 0x01; // 1<<0


    *pPortDModeReg &= ~(3<<26);   // CLEAR RESET
    *pPortDModeReg |= (1<<26);    //SET


    *pPortAModeReg &= ~(0x03);   // CLEAR RESET (3<<0)




    while(1){
    	uint8_t  pin_read= (*pPortAInReg & 0x0001);

    	if(pin_read == 1){
    		*pPortDOutReg |= (1<<13);   //SET
    	}
    	else
    	    *pPortDOutReg &= ~(1<<13);    // TURN OOF LED
    }
}
