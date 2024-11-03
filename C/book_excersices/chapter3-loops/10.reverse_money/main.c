#include <stdio.h>
#include <stdlib.h>
/*Write another version of the program from Exercise 7 so that, instead of finding the final
amount of your investment, you tell the program the final amount and it figures out how
many years it will take, at a fixed rate of interest compounded yearly, to reach this
amount. What sort of loop is appropriate for this problem? (Don’t worry about fractional
years; use an integer value for the year.)*/
int main()
{
    int total,initial,years=-1;
    float rate;
    printf("Enter the total amount: ");
    scanf("%d",&total);
    printf("Enter initial amount: ");
    scanf("%d",&initial);
    printf("Enter interest rate (percent per year):");
    scanf("%f",&rate);
    while(total>initial){
        initial=(initial+initial*(rate/100));
        years++;
    }
    printf("The Number of years : %d",years);


    return 0;
}
