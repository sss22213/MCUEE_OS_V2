#include "core.h"
typedef struct _TASK
{
        u_int_8 (*TASK1)(void);
       	u_int_8 prior;
        u_int_8 status;
        u_int_16 time_interval;
}TASK;

typedef struct _Process
{
	u_int_8 (*TASK1)(void);
	u_int_8 prior;
}Process;

//schedule
TASK schedule[TASK_Number];
//TASK excute array
Process thread[TASK_Number];

void OS_Start()
{
	for(u_int_8 i=0;i<TASK_Number;i++)
	{
		TASK_Delete(TASK_NULL,i);
		thread[i].TASK1=TASK_NULL;
	}
}

void TASK_Create(u_int_8(*TASK)(void),u_int_8 prior,u_int_8 time_interval)
{
	if(prior<1)
	{
		perror("Prior need to more than 0");
		exit(1);
	}
	if(TASK==NULL)
	{
		perror("TASK pointer to NULL TASK");
		exit(1);
	}
	if(time_interval<1)
	{	
		perror("time_interval need to more than 0");
                exit(1);
	}
	schedule[prior].TASK1=TASK;
	schedule[prior].prior=prior;
	schedule[prior].status=wait;
	schedule[prior].time_interval=time_interval;
}

void TASK_Delete(u_int_8(*TASK)(void),u_int_8 prior)
{
        if(TASK==NULL)
        {
                perror("TASK pointer to NULL TASK");
                exit(1);
        }
        schedule[prior].TASK1=TASK_NULL;
        schedule[prior].status=_sleep;
        schedule[prior].time_interval=-1;
}
void TASK_Switch()
{
	for(u_int_8 i=1;i<TASK_Number;i++)
	{
		if(schedule[i].status==wait)
		{
			if(timer1%(schedule[i].time_interval)==0)
			{
				thread[i].TASK1=*(schedule[i].TASK1);
				thread[i].prior=schedule[i].prior;
			}
		}
	}
}

void TASK_Excute()
{
	
	for(u_int_8 i=1;i<TASK_Number;i++)
	{
		//setting run in process
		schedule[thread[i].prior].prior=run;
		(thread[i].TASK1)();
		thread[i].TASK1=TASK_NULL;
		//setting wait in process
		schedule[thread[i].prior].prior=wait;
	}
	TASK_Switch();
}

u_int_8 TASK_NULL()
{
	if(1==1);
	return 0;
}


