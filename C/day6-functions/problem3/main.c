#include <stdio.h>
#include <stdlib.h>
void swap(int* x,int* y);
int main()
{
    int num1,num2;
    printf("num1:-");
    scanf("%d",&num1);
    printf("num2:-");
    scanf("%d",&num2);
    swap(&num1,&num2);
    printf("num1:-%d,num2:-%d",num1,num2);
    return 0;
}
void swap(int* x,int* y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
