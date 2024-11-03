#include <stdio.h>
#include <stdlib.h>
/* Operators such as >>, which read input from the keyboard, must be able to convert a
series of digits into a number. Write a program that does the same thing. It should allow
the user to type up to six digits, and then display the resulting number as a type long
integer. The digits should be read individually, as characters, using getche().
Constructing the number involves multiplying the existing value by 10 and then adding
the new digit*/
int main()
{
    char x[6];
    int num=0;
    for(int i=0;i<6;i++){
        x[i]=_getche();
    }
    for(int i=0;i<6;i++){
      num = num*10+((int)(x[i]-48));
    }
    printf("\n%d",num);
    return 0;
}
