#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,reverse_num=0;
    printf("Enter number: \n");
    scanf("%d",&num);
    while(num != 0){
        reverse_num=(reverse_num*10)+(num%10);
        num=num/10;
    }
    printf("reverse number :-\n%d",reverse_num);
    return 0;
}
