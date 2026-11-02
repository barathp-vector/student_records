#include"student.h"
void stud_save(ST* ptr)
{
	if(ptr==NULL)
	{
		printf("No student record found...\n");
		return;
	}
	FILE *fp = fopen("student.dat","w");
	FILE *fs = fopen("student.dat","r");
	if(fs==NULL)
		fprintf(fp,"%s %s %s\n","Roll Number","Name","Percentage");
	else
	fclose(fs);
	while(ptr!=NULL)
	{
		fprintf(fp,"%d %s %.3f\n",ptr->roll,ptr->name,ptr->mark);
		ptr = ptr->next;
	}
	fclose(fp);
	printf("Saved successfully...\n");
}
