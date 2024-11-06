#include <stdio.h>
#include <stdlib.h>
/*Add a variable of type enum etype (see Exercise 6), and another variable of type struct
date (see Exercise 5) to the employee class of Exercise 4. Organize the resulting program so that the user enters four items of information for each of three employees: an
employee number, the employee’s compensation, the employee type, and the date of first
employment. The program should store this information in three variables of type
employee, and then display their contents.
*/
struct date{
    int day;
    int month;
    int year;
};

struct employee{
int number;
float compensation;
struct date d_first;
};

int main()
{
    struct employee e1;
    struct employee e2;
    struct employee e3;
    printf("Enter employee1 number and compensation");
    printf("\nand date of first employment in the format day/month/year: \n");
    scanf("%d %f ",&e1.number,&e1.compensation);
    scanf("%d/%d/%d",&e1.d_first.day,&e1.d_first.month,&e1.d_first.year);
    printf("Enter employee2 number and compensation ");
    printf("\nand date of first employment in the format day/month/year: \n");
    scanf("%d %f",&e2.number,&e2.compensation);
    scanf("%d/%d/%d",&e2.d_first.day,&e2.d_first.month,&e2.d_first.year);
    printf("Enter employee3 number and compensation ");
    printf("\nand date of first employment in the format day/month/year: \n");
    scanf("%d %f",&e3.number,&e3.compensation);
    scanf("%d/%d/%d",&e3.d_first.day,&e3.d_first.month,&e3.d_first.year);
    printf("employee1:\nNumber:%d ,Compensation:%.2f$\n,Date of First Employment:d/%d/%d:",e1.number,e1.compensation,e1.d_first.day,e1.d_first.month,e1.d_first.year);
    printf("employee2:\nNumber:%d ,Compensation:%.2f$\n,Date of First Employment:d/%d/%d:",e2.number,e2.compensation,e2.d_first.day,e2.d_first.month,e2.d_first.year);
    printf("employee3:\nNumber:%d ,Compensation:%.2f$\n,Date of First Employment:d/%d/%d:",e3.number,e3.compensation,e3.d_first.day,e3.d_first.month,e3.d_first.year);    return 0;
}
