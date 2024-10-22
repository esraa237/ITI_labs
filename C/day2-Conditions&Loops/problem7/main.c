#include <stdio.h>
#include <stdlib.h>

int main()
{
    //flag = 0 (prime) if flag=1 (not prime)
    int number ,flag=0;
    printf("Prime Number or Not\n");
    printf("Enter the Number:- ");
    scanf("%d",&number);
    if(number==1){
        printf("Not prime number");
    }
    else if(number==2){
        printf("Prime number");
    }
    else{
        for(int i=2;i<number;i++){
            if(number%i==0){
                flag=1;
                break;
            }
        }
        if(flag==1){
            printf("Not prime number");
        }
        else{
            printf("Prime number");
        }
    }
    return 0;
}
