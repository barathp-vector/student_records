#include "student.h"
void print(ST*);
void stud_del(ST** ptr,char op)
{
    if((*ptr)==NULL)
    {
        printf("No student records...\n");
        return;
    }
    else if(op=='R' || op=='r')
    {
        printf("Enter the roll number to delete : ");
        int num;
        scanf("%d",&num);
        ST* temp = (*ptr),*prev;
        while(temp!=NULL)
        {
            if(temp->roll == num)
            {
                if((*ptr)==temp)
                    (*ptr)=(*ptr)->next;
                else 
                    prev->next = temp->next;
                free(temp);
                printf("Successfully deleted the roll number %d\n",num);
                return;
            }
            else
            {
                prev = temp;
                temp=temp->next;
            }
        }
        printf("No such roll number in the student record...\n");
    }
    else if(op=='N' || op=='n')
    {
        int count=0;
        char s[30];
        printf("Enter the name to delete : ");
        scanf("%s",s);
        ST *temp=(*ptr);
        while(temp!=NULL)
        {
            if(strcmp(s,temp->name)==0)
                count++;
            temp = temp->next;
        }
        temp = (*ptr);
        if(count==1)
        {
            ST *prev;
            while(temp!=NULL)
            {
                if(strcmp(temp->name,s)==0)
                {
                    if((*ptr)==temp)
                        (*ptr)=(*ptr)->next;
                    else
                        prev->next = temp->next;
                    free(temp);
                    printf("Successfully delete the name %s\n",s);
                    return;
                }
                else
                {
                    prev = temp;
                    temp = temp->next;
                }
            }
        }
        else if(count>1)
        {
            printf("These are all the matching names...\n\n");

            printf("--------------------------------------------------\n");
            printf("%-15s %-20s %-15s\n",
                   "Roll Number","Name","Percentage");
            printf("--------------------------------------------------\n");

            while(temp!=NULL)
            {
                if(strcmp(s,temp->name)==0)
                    print(temp);
                temp=temp->next;
            }

            printf("--------------------------------------------------\n");
            printf("So to delete Enter below roll number\n");
            stud_del(ptr,'r');
        }
        else if(count==0)
            printf("No such name in the student record...\n");
    }
}

void print(ST *p)
{
    printf("%-15d %-20s %-15.3f\n",
           p->roll,p->name,p->mark);
}

