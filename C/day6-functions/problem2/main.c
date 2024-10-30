#include <stdio.h>
#include <stdlib.h>
int getMax(int x,int y);
int main()
{
    int num1,num2;
    printf("Enter two Numbers:- \n");
    scanf("%d",&num1);
    scanf("%d",&num2);
    printf("Max:-%d ",getMax(num1,num2));
    return 0;
}
int getMax(int x,int y){
    if(x>y)return x;
    return y;
}
