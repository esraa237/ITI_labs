#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,flag;
    printf("Enter the number:- ");
    scanf("%d",&num);
    for(int i=2;i<num;i++){
        flag=1;
        if(i==2){
            printf("%d ",i);
        }
        else{
            for(int j=2;j<i;j++){
                if(i%j==0){
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                printf("%d ",i);
            }
        }
    }
    return 0;
}
