#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    int code,decimal,num1,num2;
    printf("Hello world!\n");
    printf("Enter Character :- ");
    scanf("%c",&ch);
    printf("ASCII code for %c  : %d ",ch,ch);
    printf("\nEnter ASCII Code :- ");
    scanf("%d",&code);
    printf("Character for %d  : %c ",code,code);
    printf("\nEnter decimal number:- ");
    scanf("%d",&decimal);
    printf("Hexanumber equivalent for %d  : %x ",decimal,decimal);
    printf("\nEnter two numbers :- \n");
    scanf("%d %d",&num1,&num2);
    printf("SUM : %d\n",num1+num2);
    printf("SUB : %d\n",num1-num2);
    printf("Multiplication : %d",num1*num2);
    return 0;
}
