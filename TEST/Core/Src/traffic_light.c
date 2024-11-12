/*
 * traffic_light.c
 *
 *  Created on: Oct 31, 2024
 *      Author: Admin
 */

#include "traffic_light.h"

void light_1(enum led color)
{
	switch(color){
		case red:
			HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, GPIO_PIN_SET);
			break;
		case green:
			HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, GPIO_PIN_SET);
			break;
		case yellow:
			HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, GPIO_PIN_RESET);
			break;
		case black:
			HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, GPIO_PIN_SET);
			break;
		default:
			break;
	}
}
void light_2(enum led color)
{
	switch(color){
		case red:
			HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, GPIO_PIN_SET);
			break;
		case green:
			HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, GPIO_PIN_SET);
			break;
		case yellow:
			HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, GPIO_PIN_RESET);
			break;
		case black:
			HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, GPIO_PIN_SET);
			break;
		default:
			break;
	}
}
