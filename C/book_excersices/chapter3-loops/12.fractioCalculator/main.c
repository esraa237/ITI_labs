#include <stdio.h>
#include <stdlib.h>
/*Create a four-function calculator for fractions. (See Exercise 9 in Chapter 2, and
Exercise 4 in this chapter.) Here are the formulas for the four arithmetic operations
applied to fractions:
Addition: a/b + c/d = (a*d + b*c) / (b*d)
Subtraction: a/b - c/d = (a*d - b*c) / (b*d)
Multiplication: a/b * c/d = (a*c) / (b*d)
Division: a/b / c/d = (a*d) / (b*c)
The user should type the first fraction, an operator, and a second fraction. The program
should then display the result and ask whether the user wants to continue.
*/
int main()
{
    float a,b,c,d;
    float result;
    char op,flag='y';
    while(flag=='y'){
        printf("Enter the first fraction: ");
        scanf("%f/%f",&a,&b);
        printf("Enter the operator(*/+-): ");
        _flushall();
        scanf("%c",&op);
        printf("Enter the second fraction: ");
        scanf("%f/%f",&c,&d);
        //printf("a:%.0f,b:%.0f,c:%.0f,d:%.0f",a,b,c,d);
        switch(op){
        case '+':
            result=(a*d + b*c) / (b*d);
            printf("Addition: %.0f/%.0f + %.0f/%.0f :%.2f OR %.0f/%.0f",a,b,c,d,result,(a*d+b*c),(b*d));
            break;
        case '/':
            result =(a*d)/(b*c);
            printf("Division:%.0f/%.0f / %.0f/%.0f :%.2f OR %.0f/%.0f",a,b,c,d,result,(a*d),(b*c));
            break;
        case '-':
            result =(a*d - b*c)/(b*d);
            printf("Subtraction: %.0f/%.0f - %.0f/%.0f :%.2f OR %.0f/%.0f",a,b,c,d,result,(a*d - b*c),(b*d));
            break;
        case '*':
            result = (a*c)/(b*d);
            printf("Multiplication:%.0f/%.0f * %.0f/%.0f :%.2f OR %.0f/%.0f",a,b,c,d,result,(a*c),(b*d));
            break;
        }
        printf("\nDo another (y/n)? ");
        _flushall();
        scanf("%c",&flag);
        }
    return 0;
}
