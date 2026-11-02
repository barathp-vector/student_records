#include "student.h"

void stud_show(ST* ptr)
{
    if (ptr == NULL)
    {
        printf("No Students record\n");
    }
    else
    {
        printf("--------------------------------------------------\n");
        printf("%-15s %-20s %-15s\n", "Roll Number", "Name", "Percentage");
        printf("--------------------------------------------------\n");

        while (ptr != NULL)
        {
            printf("%-15d %-20s %-15.3f\n",
                   ptr->roll,
                   ptr->name,
                   ptr->mark);

            ptr = ptr->next;
        }

        printf("--------------------------------------------------\n");
    }
}
