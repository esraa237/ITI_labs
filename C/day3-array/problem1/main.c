#include <stdio.h>
#include <stdlib.h>
#define size 5
int main()
{   int sum=0,min,max;
    int array[size];
    printf("Enter the 5 array elements:- \n");
    for(int i=0;i<size;i++){
        scanf("%d",&array[i]);
    }
    for(int i=0;i<size;i++){
       printf ("array[%d]= %d\n",i,array[i]);
       sum+=array[i];
    }
    printf("Sum:- %d\n",sum);
    max=array[0];
    min=array[0];
    for(int i=1;i<size;i++){
        if(array[i]>max){
            max=array[i];
        }
        if(array[i]<min){
            min=array[i];
        }
    }
    printf("min:- %d\n",min);
    printf("max:- %d\n",max);
    return 0;
}
