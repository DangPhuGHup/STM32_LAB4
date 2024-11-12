/*
 * scheduler.h
 *
 *  Created on: Nov 11, 2024
 *      Author: Admin
 */

//#ifndef INC_SCHEDULER_H_
//#define INC_SCHEDULER_H_
//
//#define SCH_MAX_TASKS 40
//#include <stdint.h>
//
//typedef struct{
//	void (*pTask)(void);
//	uint32_t Delay;
//	uint32_t Period;
//	uint8_t RunMe;
//
//	uint8_t TaskID;
//}sTasks;
//
//void SCH_Init(void);
//void SCH_Add_Task(void (*pFunction)(void), uint32_t DELAY, uint32_t PERIOD);
//void SCH_Update(void);
//void SCH_Dispatch_Tasks(void);
//
//#endif /* INC_SCHEDULER_H_ */




//#ifndef INC_SCHEDULER_H_
//#define INC_SCHEDULER_H_
//
//#include <stdint.h>
//
//#define SCH_MAX_TASKS 40
//
//
//typedef struct {
//    void (*pTask)(void);
//    uint32_t Delay;   // Thời gian chờ ban đầu
//    uint32_t Period;  // Chu kỳ thực thi
//    uint8_t RunMe;    // Cờ cho biết tác vụ cần được thực thi
//    uint32_t TaskID;
//} sTask;
//
//extern sTask SCH_tasks_G[SCH_MAX_TASKS];
//extern uint8_t current_index_task;
//
//
//void SCH_Init(void);
//uint32_t SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD);
//void SCH_Update(void);
//void SCH_Dispatch_Tasks(void);
//
//#endif /* INC_SCHEDULER_H_ */




#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>
#include <stdlib.h>
typedef struct {
    void (*pTask)(void);
    uint32_t Delay;
    uint32_t Period;
    uint8_t RunMe;
    uint32_t TaskID;
} sTask;

typedef struct Node {
    sTask task;
    struct Node* next;
} Node;

// Khai báo các hàm
void SCH_Init(void);
uint32_t SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD);
void SCH_Update(void);
void SCH_Dispatch_Tasks(void);
void deleteNodeByTaskID(uint32_t taskID);

#endif /* INC_SCHEDULER_H_ */


