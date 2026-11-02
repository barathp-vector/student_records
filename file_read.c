#include"student.h"
void file_read(ST **ptr)
{
	FILE *fp = fopen("student.dat","r");
	if(fp==NULL)
		return;
	int max = 100;
	while(1)
	{
		ST *new = (ST*)malloc(sizeof(ST));
		if((fscanf(fp,"%d %s %f",&new->roll,new->name,&new->mark))!=3)
		{
			free(new);
			break;
		}
		if(new->roll > max)
			max = new->roll;
		new->next = NULL;
		if((*ptr)==NULL)
			(*ptr)=new;
		else
		{
			ST *last = (*ptr);
			while(last->next!=NULL)
				last = last->next;
			last->next = new;
		}
	}
	per = max + 1;
	fclose(fp);	
}
