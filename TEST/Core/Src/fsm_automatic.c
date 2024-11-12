/*
 * fsm_automatic.c
 *
 *  Created on: Oct 31, 2024
 *      Author: Admin
 */

#include "fsm_automatic.h"
//int led_auto_buffer[3] = {5, 3, 2};
//time_red_copy = led_auto_buffer[0];
//time_green_copy = led_auto_buffer[1]; // chi lam vay de khai bao thoi
//time_yellow_copy = led_auto_buffer[2];
int led7_freq1 = 0;
int led7_freq2 = 0;

int time_red_copy = 0;
int time_green_copy = 0; // chi lam vay de khai bao thoi
int time_yellow_copy = 0;

void fsm_automatic_Run(){
	switch(status){
		  case INIT:
			  light_1(black);
			  light_2(black);
			  time_red_copy = led_auto_buffer[0];
			  time_green_copy = led_auto_buffer[1];
			  time_yellow_copy =led_auto_buffer[2];
			  status = AUTO_RED_GREEN;
			  setTimer_1s1(100);             // timer 1s
//			  setTimer_EN_GR1(freq1_led7);   // timer freg giua 2 con led7 cua 1 cum

			  break;
		  case AUTO_RED_GREEN:
			  if(timer_EN_GR1_flag == 1)
			  {
				  setTimer_EN_GR1(25);
				  switch(led7_freq1){
					  case 0:
						HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
						HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
						display_1(time_green_copy % 10);
						led7_freq1 = 1;
						break;
					  case 1:
						HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
						display_1(time_green_copy / 10);
						led7_freq1 = 0;
						break;
				  }
				  switch(led7_freq2){
					  case 0:
						HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
						HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_RESET);
						display_2(time_red_copy % 10);
						led7_freq2 = 1;
						break;
					  case 1:
						HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_SET);
						display_2(time_red_copy / 10);
						led7_freq2 = 0;
						break;
				  }
			  }
			  if(button_flag[0] == 1)
			  {
				  button_flag[0] = 0;
				  time_red_copy = led_auto_buffer[0];
				  time_green_copy = led_auto_buffer[1];
				  time_yellow_copy = led_auto_buffer[2];
				  status = INIT_MAN;
			  }
			  if(timer1_1s_flag == 1)
			  {
				  setTimer_1s1(100);
				  time_green_copy--;
				  time_red_copy--;
				  if(time_green_copy <= 0)
				  {
					  time_green_copy = led_auto_buffer[1];
					  status = AUTO_RED_YELLOW;
				  }
			  }
			  light_1(red);
			  light_2(green);
			  break;
		  case AUTO_RED_YELLOW:
			  if(timer_EN_GR1_flag == 1)
			  {
				  setTimer_EN_GR1(25);
				  switch(led7_freq1){
					  case 0:
						HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
						HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
						display_1(time_yellow_copy % 10);
						led7_freq1 = 1;
						break;
					  case 1:
						HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
						display_1(time_yellow_copy / 10);
						led7_freq1 = 0;
						break;
				  }
				  switch(led7_freq2){
					  case 0:
						HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
						HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_RESET);
						display_2(time_red_copy % 10);
						led7_freq2 = 1;
						break;
					  case 1:
						HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_SET);
						display_2(time_red_copy / 10);
						led7_freq2 = 0;
						break;
				  }
			  }
			  if(button_flag[0] == 1)
			  {
				  button_flag[0] = 0;
				  time_red_copy = led_auto_buffer[0];
				  time_green_copy = led_auto_buffer[1];
				  time_yellow_copy = led_auto_buffer[2];
				  status = INIT_MAN;
			  }
			  if(timer1_1s_flag == 1)
			  {
				  setTimer_1s1(100);
				  time_yellow_copy--;
				  time_red_copy--;
				  if(time_yellow_copy <= 0 || time_red_copy <= 0)
				  {
					  time_yellow_copy = led_auto_buffer[2];
					  time_red_copy = led_auto_buffer[0];
					  status = AUTO_GREEN_RED;
				  }
			  }
			  light_1(red);
			  light_2(yellow);
			  break;
		  case AUTO_GREEN_RED:
			  if(timer_EN_GR1_flag == 1)
			  {
				  setTimer_EN_GR1(25);
				  switch(led7_freq1){
					  case 0:
						HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
						HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
						display_1(time_red_copy % 10);
						led7_freq1 = 1;
						break;
					  case 1:
						HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
						display_1(time_red_copy / 10);
						led7_freq1 = 0;
						break;
				  }
				  switch(led7_freq2){
					  case 0:
						HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
						HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_RESET);
						display_2(time_green_copy % 10);
						led7_freq2 = 1;
						break;
					  case 1:
						HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_SET);
						display_2(time_green_copy / 10);
						led7_freq2 = 0;
						break;
				  }
			  }
			  if(button_flag[0] == 1)
			  {
				  button_flag[0] = 0;
				  time_red_copy = led_auto_buffer[0];
				  time_green_copy = led_auto_buffer[1];
				  time_yellow_copy = led_auto_buffer[2];
				  status = INIT_MAN;
			  }
			  if(timer1_1s_flag == 1)
			  {
				  setTimer_1s1(100);
				  time_red_copy--;
				  time_green_copy--;
				  if(time_green_copy <= 0)
				  {
					  time_green_copy = led_auto_buffer[1];
					  status = AUTO_YELLOW_RED;
				  }
			  }
			  light_1(green);
			  light_2(red);
			  break;
		  case AUTO_YELLOW_RED:
			  if(timer_EN_GR1_flag == 1)
			  {
				  setTimer_EN_GR1(25);
				  switch(led7_freq1){
					  case 0:
						HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
						HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
						display_1(time_red_copy % 10);
						led7_freq1 = 1;
						break;
					  case 1:
						HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
						display_1(time_red_copy / 10);
						led7_freq1 = 0;
						break;
				  }
				  switch(led7_freq2){
					  case 0:
						HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
						HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_RESET);
						display_2(time_yellow_copy % 10);
						led7_freq2 = 1;
						break;
					  case 1:
						HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_SET);
						display_2(time_yellow_copy / 10);
						led7_freq2 = 0;
						break;
				  }
			  }
			  if(button_flag[0] == 1)
			  {
				  button_flag[0] = 0;
				  time_red_copy = led_auto_buffer[0];
				  time_green_copy = led_auto_buffer[1];
				  time_yellow_copy = led_auto_buffer[2];
				  status = INIT_MAN;
			  }
			  if(timer1_1s_flag == 1)
			  {
				  setTimer_1s1(100);
				  time_red_copy--;
				  time_yellow_copy--;
				  if(time_red_copy <= 0 || time_yellow_copy <= 0)
				  {
					  time_red_copy = led_auto_buffer[0];
					  time_yellow_copy = led_auto_buffer[2];
					  status = AUTO_RED_GREEN;
				  }
			  }
			  light_1(yellow);
			  light_2(red);
			  break;
		  default:
			  break;
	  }
}

