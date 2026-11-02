#include"student.h"
void stud_add(ST** ptr)
{
	ST* new = (ST*)malloc(sizeof(ST));
	new->next=NULL;
	new->roll=per++;
	printf("Enter the name : ");
	scanf("%s",new->name);
	printf("Enter the Percentage : ");
	scanf("%f",&new->mark);
	if((*ptr)==NULL)
		(*ptr) = new;
	else
	{
		ST *temp = (*ptr);
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=new;
	}
}
