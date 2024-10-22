#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    int factorial=1;
    printf("Enter the Number: ");
    scanf("%d",&number);
    for(int i=1;i<=number;i++){
        factorial*=i;
    }
    printf("Factorial: %d",factorial);
    return 0;
}
