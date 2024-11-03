#include <stdio.h>
#include <stdlib.h>
/*
Write a program that repeatedly asks the user to enter two money amounts expressed in
old-style British currency: pounds, shillings, and pence. (See Exercises 10 and 12 in
Chapter 2, “C++ Programming Basics.”) The program should then add the two amounts
and display the answer, again in pounds, shillings, and pence. Use a do loop that asks the
user whether the program should be terminated. Typical interaction might be
Enter first amount: £5.10.6
Enter second amount: £3.2.6
Total is £8.13.0
Do you wish to continue (y/n)?
*/
int main()
{
    int pounds1,shillings1,pence1;
    int pounds2,shillings2,pence2;
    int pounds=0,shillings=0,pence=0;
    int ch1=156;
    char ch='y';
    while(ch=='y'){
    printf("Enter the first amount: %c",ch1);
    scanf("%d.%d.%d",&pounds1,&shillings1,&pence1);
    printf("Enter the second amount: %c",ch1);
    scanf("%d.%d.%d",&pounds2,&shillings2,&pence2);
    pence=pence1+pence2;
    if(pence>=12){
        shillings=pence/12;
        pence%=12;
    }
    shillings+=shillings1+shillings2;
    if(shillings>=20){
        pounds=shillings/20;
        shillings%=20;
    }
    pounds+=pounds1+pounds2;
    printf("Total: %c%d.%d.%d",ch1,pounds,shillings,pence);
    printf("\nDo you wish to continue (y/n)? ");
    _flushall();
    scanf("%c",&ch);
    }
    return 0;
}
