#include <stdio.h>
#include <stdlib.h>
void scanArr(int arr[],int size);
int sumArr(int arr[],int size);
void printArr(int arr[],int size);

int main()
{
    int arr[5];
    scanArr(arr,5);
    printf("Sum of All Elements:- %d\n",sumArr(arr,5));
    printArr(arr,5);
    return 0;
}

void scanArr(int arr[],int size){
    printf("Enter %d numbers for array:-\n",size);
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
}

int sumArr(int arr[],int size){
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=arr[i];
    }
    return sum;
}

void printArr(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("arr[%d]=%d\n",i,arr[i]);
    }
}
