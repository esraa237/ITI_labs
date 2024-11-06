#include <stdio.h>
#include <stdlib.h>
/*
Create a structure called time. Its three members, all type int, should be called hours,
minutes, and seconds. Write a program that prompts the user to enter a time value in
hours, minutes, and seconds. This can be in 12:59:59 format, or each number can be
entered at a separate prompt (“Enter hours:”, and so forth). The program should then
store the time in a variable of type struct time, and finally print out the total number of
seconds represented by this time value:
long totalsecs = t1.hours*3600 + t1.minutes*60 + t1.seconds
*/
struct time{
    int hours;
    int minutes;
    int seconds;
};
int main()
{
    struct time time;
    printf("enter a time value in hours, minutes, and seconds. This can be in 12:59:59 format: ");
    scanf("%d:%d:%d",&time.hours,&time.minutes,&time.seconds);
    int totalsec=time.hours*3600+time.minutes*60+time.seconds;
    printf("Total Seconds:%d",totalsec);
    return 0;
}
