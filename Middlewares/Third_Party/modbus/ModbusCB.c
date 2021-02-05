/*
 * ModbusCB.c
 *
 *  Created on: Jan 27, 2021
 *      Author: user
 */


#include "mb.h"

uint16_t R[15];
int idx = 0;

eMBErrorCode
eMBRegHoldingCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs, eMBRegisterMode eMode )
{
	eMBErrorCode    eStatus = MB_ENOERR;
	//static uint8_t flag = 0;
	//int i = 0;
	//flag==0 ? HAL_GPIO_WritePin(GPIOB, LD2_Pin, GPIO_PIN_SET) : HAL_GPIO_WritePin(GPIOB, LD1_Pin, GPIO_PIN_RESET);
	//flag == 0 ? HAL_GPIO_TogglePin(GPIOB, LD2_Pin) : HAL_GPIO_TogglePin(GPIOB, LD1_Pin);
	//flag ^= 1;

	/*
	if(flag==0) {
		flag = 1;
		HAL_GPIO_TogglePin(GPIOB, LD1_Pin);
		osDelay(10);
		HAL_GPIO_TogglePin(GPIOB, LD1_Pin);
		idx++;
	}else
		flag = 0;
	*/

	HAL_GPIO_TogglePin(GPIOB, LD1_Pin);
	//osDelay(10);
	//HAL_GPIO_TogglePin(GPIOB, LD1_Pin);

	/*the following code is just for the testing the function of reading register
	 author: Alan
	*/

	R[0]=98;
	R[1]=78;
	R[2]=19;
	R[3]=53;


	for(int i=0;i<usNRegs;i++) //usNRegs
	{
		//MSB
		*pucRegBuffer=R[i+usAddress-1]>>8;
		pucRegBuffer++;

		//LSB
		*pucRegBuffer=R[i+usAddress-1]&0xff;
		pucRegBuffer++;
	}


    return eStatus;
}
