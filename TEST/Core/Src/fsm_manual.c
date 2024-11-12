/*
 * fsm_manual.c
 *
 *  Created on: Nov 1, 2024
 *      Author: Admin
 */


#include "fsm_manual.h"
int timered_manual = 0;
int timegreen_manual = 0;
int timeyellow_manual = 0;

void fsm_manual_Run(){
	switch(status){
		case INIT_MAN:
			timered_manual = led_auto_buffer[0];
			timegreen_manual = led_auto_buffer[1];
			timeyellow_manual = led_auto_buffer[2];
			led7_freq1 = 0;
			led7_freq2 = 0;
			HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, GPIO_PIN_SET);

			status = MAN_RED;
		case MAN_RED:
			HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, GPIO_PIN_SET);
			if(timer_2hz_flag == 1)
			{
				setTimer_2hz(25);
				HAL_GPIO_TogglePin(RED_1_GPIO_Port, RED_1_Pin);
				HAL_GPIO_TogglePin(RED_2_GPIO_Port, RED_2_Pin);
			}
			if(button_flag[0] == 1)
			{
				button_flag[0] = 0;
				status = MAN_YELLOW;
			}
			if(button_flag[1] == 1)
			{
				button_flag[1] = 0;
				if(timered_manual < 99){
					timered_manual++;
				}
			}
			if(button_flag[2] == 1)
			{
				button_flag[2] = 0;
				if(timered_manual == (timegreen_manual + timeyellow_manual))
				{
					led_auto_buffer[0] = timered_manual;
					led_auto_buffer[1] = timegreen_manual;
					led_auto_buffer[2] = timeyellow_manual;
				}
			}
			if(timer_EN_GR1_flag == 1)
			{
				setTimer_EN_GR1(25);
				switch(led7_freq1){
					  case 0:
						HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
						HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
						display_1(timered_manual % 10);
						led7_freq1 = 1;
						break;
					  case 1:
						HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
						display_1(timered_manual / 10);
						led7_freq1 = 0;
						break;
				  }
				  switch(led7_freq2){
					  case 0:
						HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
						HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_RESET);
						display_2(1);
						led7_freq2 = 1;
						break;
					  case 1:
						HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_SET);
						display_2(0);
						led7_freq2 = 0;
						break;
				  }
			}
			break;
		case MAN_YELLOW:
			HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, GPIO_PIN_SET);
			if(timer_2hz_flag == 1)
			{
				setTimer_2hz(25);
				HAL_GPIO_TogglePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin);
				HAL_GPIO_TogglePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin);
			}
			if(button_flag[0] == 1)
			{
				button_flag[0] = 0;
				status = MAN_GREEN;
			}
			if(button_flag[1] == 1)
			{
				button_flag[1] = 0;
				if(timeyellow_manual < 99){
					timeyellow_manual++;
				}
			}
			if(button_flag[2] == 1)
			{
				button_flag[2] = 0;
				if(timered_manual == (timegreen_manual + timeyellow_manual))
				{
					led_auto_buffer[0] = timered_manual;
					led_auto_buffer[1] = timegreen_manual;
					led_auto_buffer[2] = timeyellow_manual;
				}
			}
			if(timer_EN_GR1_flag == 1)
			{
				setTimer_EN_GR1(25);
				switch(led7_freq1){
					  case 0:
						HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
						HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
						display_1(timeyellow_manual % 10);
						led7_freq1 = 1;
						break;
					  case 1:
						HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
						display_1(timeyellow_manual / 10);
						led7_freq1 = 0;
						break;
				  }
				  switch(led7_freq2){
					  case 0:
						HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
						HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_RESET);
						display_2(2);
						led7_freq2 = 1;
						break;
					  case 1:
						HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_SET);
						display_2(0);
						led7_freq2 = 0;
						break;
				  }
			}
			break;
		case MAN_GREEN:
			HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, GPIO_PIN_SET);
			if(timer_2hz_flag == 1)
			{
				setTimer_2hz(25);
				HAL_GPIO_TogglePin(GREEN_1_GPIO_Port, GREEN_1_Pin);
				HAL_GPIO_TogglePin(GREEN_2_GPIO_Port, GREEN_2_Pin);
			}
			if(button_flag[0] == 1)
			{
				button_flag[0] = 0;
				timered_manual = led_auto_buffer[0];
				timegreen_manual = led_auto_buffer[1];
				timeyellow_manual = led_auto_buffer[2];
				status = INIT;
			}
			if(button_flag[1] == 1)
			{
				button_flag[1] = 0;
				if(timegreen_manual < 99){
					timegreen_manual++;
				}
			}
			if(button_flag[2] == 1)
			{
				button_flag[2] = 0;
				if(timered_manual == (timegreen_manual + timeyellow_manual))
				{
					led_auto_buffer[0] = timered_manual;
					led_auto_buffer[1] = timegreen_manual;
					led_auto_buffer[2] = timeyellow_manual;
				}
			}
			if(timer_EN_GR1_flag == 1)
			{
				setTimer_EN_GR1(25);
				switch(led7_freq1){
					  case 0:
						HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
						HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
						display_1(timegreen_manual % 10);
						led7_freq1 = 1;
						break;
					  case 1:
						HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
						display_1(timegreen_manual / 10);
						led7_freq1 = 0;
						break;
				  }
				  switch(led7_freq2){
					  case 0:
						HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
						HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_RESET);
						display_2(3);
						led7_freq2 = 1;
						break;
					  case 1:
						HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_SET);
						display_2(0);
						led7_freq2 = 0;
						break;
				  }
			}
			break;
		default:
			break;
	}
}
