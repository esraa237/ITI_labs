#include <stdio.h>
#include <stdlib.h>

int main()
{
    //problem 1
    int degree;
    printf("Display your Grade\n");
    printf("Enter your degree:- ");
    scanf("%d",&degree);
    if(degree>=85)
        printf("Excellent");
    else if(degree>=75)
        printf("VGood");
    else if(degree>=65)
        printf("Good");
    else if(degree>=60)
        printf("accepted");
    else
        printf("fail");

    return 0;
}
