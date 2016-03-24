#ifndef _core_H
#define _core_H

#include <stdio.h>
#include <stdlib.h>

#define TASK_Number 20

//TASK struct
typedef struct _TASK TASK;
typedef struct _Process Process;
//symbol table
typedef unsigned char u_int_8;
typedef signed char s_int_8;
typedef unsigned int u_int_16;
typedef int s_int_16;
//define error variable 
typedef unsigned char err;

//Systick timer
u_int_16 timer1;

/******************************/
//define process status 
enum
{
	run=0,
	wait=1,
	_sleep=2,
};

/*****************************/
//function declare
//NULL function
u_int_8 TASK_NULL();
void TASK_Create(u_int_8(*TASK)(void),u_int_8 prior,u_int_8 time_interval);
void TASK_Delete(u_int_8(*TASK)(void),u_int_8 prior);
void TASK_Excute();
void OS_Start();

#endif
