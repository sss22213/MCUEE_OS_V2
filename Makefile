all:
	gcc -o main main.c core.c mail.c core.h mail.h -std=c99 -g -Wall
