#MCUEE-OS-V2
Simple Time-Sharing and Task Scheduler Dispatch

#ChangLog:
2016/03/25:

Kernel V2.0:

Basic Task Scheduler and Time-Sharing

Basic TASK value deliver 

#1.Test Environment
Linux kernel 4.4

GNU GCC 5.3

C99

#2.How to use test program?
1.make main

2.execute "main"

#3.How to transplant?
1.Need to Systick let's timer increase.

2.Add OS_Start() in your program startup.

3.Add TASK_Create() in your program

4.Execute "TASK_Excute()" after timer increase

#4.For Embedded
Arduino test not ready!

AT89S51 is not support(Programmer size is so giant.Only support for few TASK)

PIC18F4520 test not ready!

STM32F407 test not ready!

#5 diff(V1 and V2)
1.using new structure in Task Scheduler

2.TASK return data type from int to u_int_8

3.using symbol table

4.TASK value deliver System
