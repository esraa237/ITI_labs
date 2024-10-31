#include <stdio.h>
#include <stdlib.h>
//one dimention dynamic array
int main()
{
    int size;
    printf("Enter Size of array:- ");
    scanf("%d",&size);
    int * ptr=(int*)malloc(size*sizeof(int));
    if(ptr!=NULL){
        printf("Enter Elements of the array:\n");
        for(int i=0;i<size;i++){
            scanf("%d",ptr+i);
        }
        for(int i=0;i<size;i++){
            printf("arr[%d]:-%d\n",i,ptr[i]);
        }
        free(ptr);
    }
    return 0;
}
