#include <stdio.h>
#include <stdlib.h>
int factorial(int num);

int main()
{
    int num;
    printf("Enter the num:- ");
    scanf("%d",&num);
    printf("Factorial:- %d",factorial(num));
    return 0;
}

int factorial(int num){
    int fact=1;
    for(int i=1;i<=num;i++){
        fact*=i;
    }
    return fact;
}
