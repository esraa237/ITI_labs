#include <stdio.h>
#include <stdlib.h>
/*
Modify the FACTOR program in this chapter so that it repeatedly asks for a number and
calculates its factorial, until the user enters 0, at which point it terminates. You can
enclose the relevant statements in FACTOR in a while loop or a do loop to achieve this
effect.
*/
int main()
{
    int num,fact=1;
    char ch='y';
    while(ch=='y'){
        printf("Enter the number: ");
        scanf("%d",&num);
        for(int i=0;i<num;i++){
            fact*=num-i;
        }
        printf("Factorial: %d",fact);
        printf("\nDo you wish to continue (y/n)? ");
        _flushall();
        scanf("%c",&ch);
    }
    return 0;
}
