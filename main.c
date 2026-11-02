#include"student.h"
int per=101;
int main()
{
	ST *hptr = NULL;
	char op;
	file_read(&hptr);
	while(1)
	{
top:
		printf("*******************************\n");
		printf("****  STUDENT RECORD MENU  ****\n");
		printf("*******************************\n");
		printf("*    [A] : Add New Record     *\n");
		printf("*    [D] : Delete a Record    *\n");
		printf("*    [S] : Show the List      *\n");
		printf("*    [M] : Modify a Record    *\n");
		printf("*    [V] : Save               *\n");
		printf("*    [T] : Sort the List      *\n");
		printf("*    [E] : Exit               *\n");
		printf("*******************************\n");
		printf("\n");
		printf("Enter Your Choice: ");
		scanf(" %c",&op);
		printf("\n");
		if(op=='A' || op=='a')
			stud_add(&hptr);
		else if(op=='D'||op=='d')
		{
s1:
			printf("[R] : Delete using Roll Number\n");
			printf("[N] : Delete using Name\n");
			printf("[G] : Go back\n");
			printf("Enter the option:");
			scanf(" %c",&op);
			printf("\n");
			if(!(op=='R' || op=='r' || op=='N' || op=='n'||op=='g'||op=='G'))
			{
				printf("Enter correct option....");
				goto s1;
			}
			else if(op=='g'||op=='G')
				goto top;
			else
				stud_del(&hptr,op);
		}
		else if(op=='S'||op=='s')
			stud_show(hptr);
		else if(op=='M'||op=='m')
		{
s3:
			printf("[R] : Roll Number\n");
			printf("[N] : Name\n");
			printf("[P] : Percentage\n");
			printf("[G] : Go back\n");
			printf("Enter your choice : ");
			scanf(" %c",&op);
			if(!(op=='R'||op=='r'||op=='N'||op=='n'||op=='P'||op=='p'||op=='g'||op=='G'))
			{
				printf("Enter correct option\n");
				goto s3;
			}
			else if(op=='g'||op=='G')
				goto top;
			else 
				stud_mod(hptr,op);
		}
		else if(op=='V'||op=='v')
			stud_save(hptr);
		else if(op=='T'||op=='t')
		{
s4:
			printf("[N] : Sort by Name\n");
			printf("[P] : Sort by Percentage\n");
			printf("[G] : Go back\n");
			printf("Enter your choice : ");
			scanf(" %c",&op);
			if(!(op=='N'||op=='n'||op=='P'||op=='p'||op=='g'||op=='G'))
			{
				printf("Enter correct option\n");
				goto s4;
			}
			else if(op=='G'||op=='g')
				goto top;
			else
				stud_sort(hptr,op);
		}
		else if(op=='E'||op=='e')
		{
s2:
			printf("[S] : Save and Exit\n");
			printf("[E] : Exit without saving\n");
			printf("[G] : Go back\n");
			printf("Enter the choice : ");
			scanf(" %c",&op);
			if(op=='S'||op=='s')
			{
				stud_save(hptr);
				break;
			}
			else if(op=='e'||op=='E')
				break;
			else if(op=='G'||op=='g')
				goto top;
			else
			{
				printf("Enter correct option\n");
				goto s2;
			}
		}
		else
			printf("Enter the correct option....");
		printf("\n");
	}
}
