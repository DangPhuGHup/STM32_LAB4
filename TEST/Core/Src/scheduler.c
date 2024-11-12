/*
 * scheduler.c
 *
 *  Created on: Nov 11, 2024
 *      Author: Admin
 */

//#include "scheduler.h"
//
//sTasks SCH_tasks_G[SCH_MAX_TASKS];
//uint8_t current_index_task = 0;
//
//void SCH_Init(void)
//{
//	current_index_task = 0;
//}
//void SCH_Add_Task(void (*pFunction)(void), uint32_t DELAY, uint32_t PERIOD)
//{
//	if(current_index_task < SCH_MAX_TASKS){
//		SCH_tasks_G[current_index_task].pTask = pFunction;
//		SCH_tasks_G[current_index_task].Delay = DELAY;
//		SCH_tasks_G[current_index_task].Period = PERIOD;
//		SCH_tasks_G[current_index_task].RunMe = 0;
//		SCH_tasks_G[current_index_task].TaskID = current_index_task;
//
//		current_index_task ++;
//	}
//}
//void SCH_Update(void)
//{
//	for(int i = 0; i < current_index_task; i++){
//		if(SCH_tasks_G[i].Delay > 0){
//			SCH_tasks_G[i].Delay --;
//		} else {
//			SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
//			SCH_tasks_G[i].RunMe += 1;
//		}
//	}
//}
//void SCH_Dispatch_Tasks(void){
//	for(int i = 0; i < current_index_task; i++){
//		if(SCH_tasks_G[i].RunMe > 0){
//			SCH_tasks_G[i].RunMe--;
//			(*SCH_tasks_G[i].pTask)();
//		}
//	}
//}






//#include "scheduler.h"
//
//sTask SCH_tasks_G[SCH_MAX_TASKS];
//uint8_t current_index_task = 0;
//
//void SCH_Init(void) {
//    current_index_task = 0;
//    for (int i = 0; i < SCH_MAX_TASKS; i++) {
//        SCH_tasks_G[i].pTask = 0;
//        SCH_tasks_G[i].Delay = 0;
//        SCH_tasks_G[i].Period = 0;
//        SCH_tasks_G[i].RunMe = 0;
//        SCH_tasks_G[i].TaskID = 0;
//    }
//}
//
//uint32_t SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD) {
//    uint32_t Index = 0;
//    // Tìm vị trí trống trong mảng task
//    while ((SCH_tasks_G[Index].pTask != 0) && (Index < SCH_MAX_TASKS)) {
//        Index++;
//    }
//
//    // Kiểm tra nếu mảng task đã đầy
//    if (Index == SCH_MAX_TASKS) {
//        // Mảng task đầy
//        return SCH_MAX_TASKS;
//    }
//
//    SCH_tasks_G[Index].pTask = pFunction;
//    SCH_tasks_G[Index].Delay = DELAY;
//    SCH_tasks_G[Index].Period = PERIOD;
//    SCH_tasks_G[Index].RunMe = 0;
//    SCH_tasks_G[Index].TaskID = Index;
//
//    current_index_task++;
//
//    return Index;
//}
//
//void SCH_Update(void) {
//    // Hàm này được gọi mỗi tick (ví dụ mỗi 10ms)
//    for (int i = 0; i < SCH_MAX_TASKS; i++) {
//        if (SCH_tasks_G[i].pTask) {
//        	  if(SCH_tasks_G[i].Delay > 0){
//        		  SCH_tasks_G[i].Delay--;
//        	  }
//        	  if(SCH_tasks_G[i].Delay == 0){
//        		  SCH_tasks_G[i].RunMe += 1;
//        		  if (SCH_tasks_G[i].Period) {
//        			      SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
//				  }
//			  }
//        }
//	}
//
//}
//
//void SCH_Dispatch_Tasks(void) {
//    for (int i = 0; i < SCH_MAX_TASKS; i++) {
//        if (SCH_tasks_G[i].RunMe > 0) {
//            (*SCH_tasks_G[i].pTask)(); // Thực thi tác vụ
//            SCH_tasks_G[i].RunMe -= 1;
//
//            // Nếu tác vụ không có chu kỳ (Period = 0), xóa tác vụ sau khi thực thi
//            if (SCH_tasks_G[i].Period == 0) {
//                SCH_tasks_G[i].pTask = 0;
//                current_index_task--;
//            }
//        }
//    }
//}





#include "scheduler.h"

Node* head = NULL;
uint32_t current_task_id = 0;
uint8_t Update_flag = 0;
void SCH_Init(void) {
    head = NULL;
    current_task_id = 0;
}

Node* createNode(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return NULL;

    newNode->task.pTask = pFunction;
    newNode->task.Delay = DELAY;
    newNode->task.Period = PERIOD;
    newNode->task.RunMe = 0;
    newNode->task.TaskID = current_task_id++;
    newNode->next = NULL;

    return newNode;
}

uint32_t SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD) {
    Node* newNode = createNode(pFunction, DELAY, PERIOD);
    if (!newNode) return current_task_id;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return newNode->task.TaskID;
}

void SCH_Update(void) {
	Update_flag = 1;
}

void SCH_Dispatch_Tasks(void) {
    if (Update_flag == 1)
    {
    	Update_flag = 0;
    	Node* temp = head;
    	while (temp != NULL) {
			if (temp->task.Delay > 0) {
				temp->task.Delay--;
			}
			if (temp->task.Delay == 0) {
				(*temp->task.pTask)(); // Thực thi tác vụ
				if (temp->task.Period) {
					temp->task.Delay = temp->task.Period;
				}
				else {
					deleteNodeByTaskID(temp->task.TaskID);
					temp = head;
					continue;
				}
			}
			temp = temp->next;
		}
    }
}

void deleteNodeByTaskID(uint32_t taskID) {
    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->task.TaskID != taskID) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    if (prev == NULL) { // Xóa node đầu
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
}











