#include <stdio.h>
#include <stdlib.h>
/*
Create a structure called employee that contains two members: an employee number
(type int) and the employee’s compensation (in dollars; type float). Ask the user to fill
in this data for three employees, store it in three variables of type struct employee, and
then display the information for each employee.
*/
struct employee{
int number;
float compensation;
};
int main()
{
    struct employee e1;
    struct employee e2;
    struct employee e3;
    printf("Enter employee1 number and compensation: ");
    scanf("%d %f",&e1.number,&e1.compensation);
    printf("Enter employee2 number and compensation: ");
    scanf("%d %f",&e2.number,&e2.compensation);
    printf("Enter employee3 number and compensation: ");
    scanf("%d %f",&e3.number,&e3.compensation);
    printf("employee1:\nNumber:%d ,Compensation:%.2f$\n",e1.number,e1.compensation);
    printf("employee2:\nNumber:%d ,Compensation:%.2f$\n",e2.number,e2.compensation);
    printf("employee3:\nNumber:%d ,Compensation:%.2f$",e3.number,e3.compensation);
    return 0;
}
