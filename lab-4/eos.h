#ifndef _EOS_H
#define _EOS_H

#include "project.h"

typedef struct {
void(*pTask)(void);
tWord Delay;
tWord Repeat;
tByte RunMe;
} sTask;

tWord Delay;
tWord Repeat;
tByte RunMe;

void SCH_Init(void);
void SCH_AddTask(	void (*fPtr)(void),
					tWord DELAY,
					tWord REPEAT);
void SCH_Update(void);
void SCH_Dispatch(void);
tByte SCH_Delete_Task(tByte taskIndex);

#endif
