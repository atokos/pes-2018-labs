#include "project.h"
#include "eos.h"

#define MAX_TASKS (5)

sTask gTaskList[MAX_TASKS];

void SCH_Init(void) {
    __enable_interrupt();
}

void SCH_AddTask(void (*fPtr)(void), tWord Delay, tWord Repeat) { 
	tByte i;
	for (i=0;i<MAX_TASKS; i++) {
		if(!gTaskList[i].pTask) {
			gTaskList[i].pTask = fPtr;
			gTaskList[i].Delay = Delay + 1;
			gTaskList[i].Repeat =  Repeat; 
			gTaskList[i].RunMe = 0;
			return;
		}
	}
	return;
}

void SCH_Update(void) {
	tByte i;
	for(i = 0; i < MAX_TASKS; i++) {
		if(gTaskList[i].pTask){
			if(--gTaskList[i].Delay == 0){
				gTaskList[i].RunMe++;
				if(gTaskList[i].Repeat) {
					gTaskList[i].Delay = gTaskList[i].Repeat;
				}
			}
		}
	}
}

void SCH_Dispatch(void) {
	tByte idx;
	for(idx=0; idx<MAX_TASKS;idx++) {
		if(gTaskList[idx].RunMe>0) {
			(*gTaskList[idx].pTask)();
			gTaskList[idx].RunMe--;
			if(gTaskList[idx].Repeat == 0) {
				SCH_Delete_Task(idx);
			}
		}
	} 
}

tByte SCH_Delete_Task(tByte idx) {
	
	tByte Return_code;
	
	if(gTaskList[idx].pTask == 0){
		
		//Error_code_G = ERROR_SCH_CANNOT_DELETE_TASK; 
		
		//Return_code = RETURN_ERROR;
	}
	else {
		//Return_code = NORMAL;
	}
	
	gTaskList[idx].pTask = 0x0000;
	gTaskList[idx].Delay = 0;
	gTaskList[idx].Repeat = 0;
	gTaskList[idx].RunMe = 0;
	
	return Return_code;
}
