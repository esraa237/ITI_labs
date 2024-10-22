#include <stdio.h>
#include <stdlib.h>

int main()
{
    //problem 3
    int month;
    printf("Days in Month\n");
    printf("Enter the Number of the Month :- ");
    _flushall();
    scanf("%d",&month);
    switch(month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("Days in Month%d : 31 ",month);
            break;
        case 2:
            printf("Days in Month%d : 28 ",month);
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            printf("Days in Month%d : 30 ",month);
            break;
    }
    return 0;
}
