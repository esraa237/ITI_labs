#include <stdio.h>
#include <stdlib.h>
/*Create a structure of type date that contains three members: the month, the day of the
month, and the year, all of type int. (Or use day-month-year order if you prefer.) Have
the user enter a date in the format 12/31/2001, store it in a variable of type struct date,
then retrieve the values from the variable and print them out in the same format.*/
struct date{
    int day;
    int month;
    int year;
};
int main()
{
    struct date d1;
    printf("Enter a date in the format day/month/year: ");
    scanf("%d/%d/%d",&d1.day,&d1.month,&d1.year);
    printf("Date you Enter :%d/%d/%d",d1.day,d1.month,d1.year);
    return 0;
}
