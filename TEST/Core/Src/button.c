/*
 * button.c
 *
 *  Created on: Nov 1, 2024
 *      Author: Admin
 */

#include "button.h"

int keyReg0[NUMBER_of_BUTTONS] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int keyReg1[NUMBER_of_BUTTONS] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int keyReg2[NUMBER_of_BUTTONS] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int keyRegPrevious[NUMBER_of_BUTTONS] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int timer_keypress[NUMBER_of_BUTTONS] = {0 , 0, 0};
int button_flag[NUMBER_of_BUTTONS] = {0, 0, 0};

void subkey(int button_index){
	button_flag[button_index] = 1;
}

void getKeyInput(){
	for(int i = 0; i < NUMBER_of_BUTTONS; i++){
		keyReg0[i] = keyReg1[i];
		keyReg1[i] = keyReg2[i];
	}
	keyReg2[0] = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
	keyReg2[1] = HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port, BUTTON_2_Pin);
	keyReg2[2] = HAL_GPIO_ReadPin(BUTTON_3_GPIO_Port, BUTTON_3_Pin);

	for(int i = 0; i < NUMBER_of_BUTTONS; i++)
	{
		if((keyReg0[i] == keyReg1[i]) && (keyReg1[i] == keyReg2[i])){  // bước chống nhiễu 20ms, vì hàm này
				                                               // được gọi trong ngắt 10ms.
			if(keyRegPrevious[i] != keyReg2[i]){  // trạng thái nhấn rồi thả, không phải nhấn đè.
				keyRegPrevious[i] = keyReg2[i];   // đưa trạng thái cũ vào trạng thái đang nhấn mới.
				if(keyReg2[i] == PRESSED_STATE) // cho biết là trong trường hợp đã nhấn
				{
					subkey(i);              // thực hiện hàm tùy ý.
					timer_keypress[i] = 200;  // nhấn đề 2s mới chuyển sang trạng thái nhấn đè ở dưới.
										   // thời gian để chuyển trạng thái sang nhấn đè.
				}
			}
			else{  // trạng thái nhấn đè hoặc lúc không nhấn
				if(keyReg2[i] == PRESSED_STATE){   // xac dinh no la trang thai nhan de
					timer_keypress[i]--;
					if(timer_keypress[i] <= 0)     // da den luc thuc hien nhan de
					{
						subkey(i);
						timer_keypress[i] = 50;   // thoi gian giua cac lenh thuc thi khi nhan de
					}
				}
				else{
					timer_keypress[i] = 0;
				}
			}
		}
	}
}
