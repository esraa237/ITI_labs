#include <stdio.h>
#include <stdlib.h>
/*
A phone number, such as (212) 767-8900, can be thought of as having three parts: the
area code (212), the exchange (767), and the number (8900). Write a program that uses a
structure to store these three parts of a phone number separately. Call the structure
phone. Create two structure variables of type phone. Initialize one, and have the user
input a number for the other one. Then display both numbers. The interchange might
look like this:
Enter your area code, exchange, and number: 415 555 1212
My number is (212) 767-8900
Your number is (415) 555-1212
*/
struct phone{
    int code;
    int exchange;
    int number;
};
int main()
{
    struct phone p1;
    p1.code=212;
    p1.exchange=767;
    p1.number=8900;
    struct phone p2;
    printf("Enter your area code, exchange, and number: ");
    scanf("%d %d %d",&p2.code,&p2.exchange,&p2.number);
    printf("My number is (%d) %d-%d\n",p1.code,p1.exchange,p1.number);
    printf("Your number is (%d) %d-%d",p2.code,p2.exchange,p2.number);

    return 0;
}
