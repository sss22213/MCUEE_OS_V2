#include "core.h"
#include "mail.h"
#include <unistd.h>


u_int_8 task1()
{
  printf("I am first task\n");
  return 0;
}
u_int_8 task2()
{
  printf("I am second task\n");
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

    //print timer value
    printf("timer:%d\n",timer1);

    //delay 1s
    sleep(1);
  }
	return 0;
}
