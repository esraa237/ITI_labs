#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[5]={0};
    int* ptr=arr;
    printf("Enter 5 numbers:- \n");
    for(int i=0;i<5;i++){
      scanf("%d",ptr+i);
    }
    printf("Array:- \n");
    for(int i=0;i<5;i++){
      printf("%d\n",*ptr+i);
    }



    return 0;
}
