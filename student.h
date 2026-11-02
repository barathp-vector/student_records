#include<stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include<stdlib.h>
#include<string.h>
typedef struct student
{
	int roll;
	char name[30];
	float mark;
	struct student *next;
}ST;
void file_read(ST**);
void stud_add(ST**);
void stud_del(ST**,char);
void stud_show(ST*);
void stud_mod(ST*,char);
void stud_save(ST*);
void stud_sort(ST*,char);
extern int per;
extern int count;
extern ST* curr;
