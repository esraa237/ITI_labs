#include <stdio.h>
#include <stdlib.h>
/* Suppose you give a dinner party for six guests, but your table seats only four. In how
many ways can four of the six guests arrange themselves at the table? Any of the six
guests can sit in the first chair. Any of the remaining five can sit in the second chair. Any
of the remaining four can sit in the third chair, and any of the remaining three can sit in
the fourth chair. (The last two will have to stand.) So the number of possible arrangements of six guests in four chairs is 6*5*4*3, which is 360. Write a program that calculates the number of possible arrangements for any number of guests and any number of
chairs.*/
int main()
{
    int chairs,guests,p_arrangement=1;
    printf("Enter the number of chairs: ");
    scanf("%d",&chairs);
    printf("Enter the number of guests: ");
    scanf("%d",&guests);
    for(int i=0;i<chairs;i++){
        p_arrangement*=guests-i;
    }
     printf("Possible Arrangement: %d",p_arrangement);
    return 0;
}
