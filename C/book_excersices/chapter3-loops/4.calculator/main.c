#include <stdio.h>
#include <stdlib.h>
/*Create the equivalent of a four-function calculator. The program should ask the user to
enter a number, an operator, and another number. (Use floating point.) It should then
carry out the specified arithmetical operation: adding, subtracting, multiplying, or dividing the two numbers. Use a switch statement to select the operation. Finally, display the
result.
When it finishes the calculation, the program should ask whether the user wants to do
another calculation. The response can be ‘y’ or ‘n’.*/
int main()
{
    float num1,num2;
    char op,flag='y';
    while(flag=='y'){
      printf("Enter first number, operator, second number: ");
      scanf("%f %c %f",&num1,&op,&num2);
      switch (op){
        case '+':
            printf("Answer : %.1f",num1+num2);
            break;
        case '-':
            printf("Answer : %.1f",num1-num2);
            break;
        case '/':
            printf("Answer : %.3f",num1/num2);
            break;
        case '*':
            printf("Answer : %.1f",num1*num2);
            break;
      }
      printf("\nDo another (y/n)? ");
      scanf("%c",&flag);
    }

    return 0;
}
