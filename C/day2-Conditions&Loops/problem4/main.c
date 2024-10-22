#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum=0,temp;
    printf("Enter 5 Numbers:- \n");
    for(int i=0;i<5;i++){
        scanf("%d",&temp);
        sum +=temp;
    }
    printf("Sum :- %d",sum);
    return 0;
}
