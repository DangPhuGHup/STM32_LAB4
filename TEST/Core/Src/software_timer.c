/*
 * software_timer.c
 *
 *  Created on: Oct 31, 2024
 *      Author: Admin
 */

#include "software_timer.h"

int timer1_1s_counter = 100;
int timer1_1s_flag = 0;
int timer_EN_GR1_counter = 0;
int timer_EN_GR1_flag = 1;
int timer_2hz_counter = 0;
int timer_2hz_flag = 1;

void setTimer_1s1(int duration)
{
	timer1_1s_counter = duration;
	timer1_1s_flag = 0;
}
void setTimer_EN_GR1(int duration)
{
	timer_EN_GR1_counter = duration;
	timer_EN_GR1_flag = 0;
}
void setTimer_2hz(int duration)
{
	timer_2hz_counter = duration;
	timer_2hz_flag = 0;
}
void timerRun()
{
	if(timer1_1s_counter > 0)
	{
		timer1_1s_counter--;
		if(timer1_1s_counter <= 0)
		{
			timer1_1s_flag = 1;
		}
	}
	if(timer_EN_GR1_counter > 0)
	{
		timer_EN_GR1_counter--;
		if(timer_EN_GR1_counter <= 0)
		{
			timer_EN_GR1_flag = 1;
		}
	}
	if(timer_2hz_counter > 0)
	{
		timer_2hz_counter--;
		if(timer_2hz_counter <= 0)
		{
			timer_2hz_flag = 1;
		}
	}
}
