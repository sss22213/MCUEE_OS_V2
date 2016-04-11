#include "core.h"
#include "mail.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
u_int_8 task1()
{
	printf("I am first task\n");
	//put output argument into box1[1]
	Put_mail(1,2);
	return 0;
}
u_int_8 task2()
{
	printf("I am second task\n");
	//put output argument from task1 to box1[2]
	Put_mail(2,Get_mail(1)+1);
	return 0;
}
u_int_8 task3()
{
	printf("I am third task\n");
	return 0;
}

int main()
{
	OS_Start();
	//TASK Create
	TASK_Create(task1,1,2);
	TASK_Create(task2,2,5);
	TASK_Create(task3,5,6);
	while(1)
	{
		timer1++;
		TASK_Excute();
		printf("%d\n",timer1);
		sleep(1);
	}
	return 0;
}
