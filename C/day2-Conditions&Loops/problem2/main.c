#include <stdio.h>
#include <stdlib.h>

int main()
{
     //problem 2
    int num1,num2;
    char op;
    printf("Calculator\n");
    printf("Enter the two numbers :- \n");
    scanf("%d",&num1);
    scanf("%d",&num2);
    printf("Enter the operator (+,-,*,/) :- \n");
    _flushall();
    scanf("%c",&op);
    switch(op){
        case '+':
            printf("%d + %d = %d",num1,num2,num1+num2);
            break;
        case '-':
            printf("%d - %d = %d",num1,num2,num1-num2);
            break;
        case '*':
            printf("%d * %d = %d",num1,num2,num1*num2);
            break;
        case '/':
            printf("%d / %d = %d",num1,num2,num1/num2);
            break;
        default:
            printf("Wrong Operator");
            break;
    }
    return 0;
}
