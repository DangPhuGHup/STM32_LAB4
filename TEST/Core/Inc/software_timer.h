/*
 * software_timer.h
 *
 *  Created on: Oct 31, 2024
 *      Author: Admin
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_1s_flag;
extern int timer_EN_GR1_flag;
extern int timer_2hz_flag;
void setTimer_1s1(int duration);
void setTimer_EN_GR1(int duration);
void setTimer_2hz(int duration);
void timerRun();
#endif /* INC_SOFTWARE_TIMER_H_ */
