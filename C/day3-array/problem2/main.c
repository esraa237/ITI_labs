#include <stdio.h>
#include <stdlib.h>
#define row 2
#define column 2
int main()
{
    int sum[row]={0};
    int arr[row][column];
    printf("Enter the array elements:- \n");
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            printf("arr[%d][%d] = ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            printf("\narr[%d][%d] = %d ",i,j,arr[i][j]);
            sum[i]+=arr[i][j];
        }
    }
    for(int i=0;i<row;i++){
        printf("\nSum[%d] = %d ",i,sum[i]);
    }
    return 0;
}
