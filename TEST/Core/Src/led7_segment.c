/*
 * led7_segment.c
 *
 *  Created on: Oct 31, 2024
 *      Author: Admin
 */
#include "led7_segment.h"

void display_1(int num)
{
	switch(num)
	{
		case 0:
				  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_SET);
				  break;
		case 1:
				  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_SET);
				  break;
		case 2:
				  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_RESET);
				  break;
		case 3:
				  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_RESET);
				  break;
		case 4:
				  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_RESET);
				  break;
		case 5:
				  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_RESET);
				  break;
		case 6:
				  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_RESET);
				  break;
		case 7:
				  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_SET);
				  break;
		case 8:
				  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_RESET);
				  break;
		case 9:
				  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_RESET);
				  break;
		default:
				  break;
	}
}
void display_2(int num)
{
	switch(num)
	{
		case 0:
				  HAL_GPIO_WritePin(GPIOB, SEG10_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG11_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG12_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG13_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG14_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG15_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG16_Pin, GPIO_PIN_SET);
				  break;
		case 1:
				  HAL_GPIO_WritePin(GPIOB, SEG10_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG11_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG12_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG13_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG14_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG15_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG16_Pin, GPIO_PIN_SET);
				  break;
		case 2:
				  HAL_GPIO_WritePin(GPIOB, SEG10_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG11_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG12_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG13_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG14_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG15_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG16_Pin, GPIO_PIN_RESET);
				  break;
		case 3:
				  HAL_GPIO_WritePin(GPIOB, SEG10_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG11_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG12_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG13_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG14_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG15_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG16_Pin, GPIO_PIN_RESET);
				  break;
		case 4:
				  HAL_GPIO_WritePin(GPIOB, SEG10_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG11_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG12_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG13_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG14_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG15_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG16_Pin, GPIO_PIN_RESET);
				  break;
		case 5:
				  HAL_GPIO_WritePin(GPIOB, SEG10_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG11_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG12_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG13_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG14_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG15_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG16_Pin, GPIO_PIN_RESET);
				  break;
		case 6:
				  HAL_GPIO_WritePin(GPIOB, SEG10_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG11_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG12_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG13_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG14_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG15_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG16_Pin, GPIO_PIN_RESET);
				  break;
		case 7:
				  HAL_GPIO_WritePin(GPIOB, SEG10_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG11_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG12_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG13_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG14_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG15_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG16_Pin, GPIO_PIN_SET);
				  break;
		case 8:
				  HAL_GPIO_WritePin(GPIOB, SEG10_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG11_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG12_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG13_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG14_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG15_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG16_Pin, GPIO_PIN_RESET);
				  break;
		case 9:
				  HAL_GPIO_WritePin(GPIOB, SEG10_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG11_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG12_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG13_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG14_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOB, SEG15_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG16_Pin, GPIO_PIN_RESET);
				  break;
		default:
				  break;
	}
}

