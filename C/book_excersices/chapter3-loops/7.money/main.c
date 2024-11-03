#include <stdio.h>
#include <stdlib.h>
/*Write a program that calculates how much money you’ll end up with if you invest an
amount of money at a fixed interest rate, compounded yearly. Have the user furnish the
initial amount, the number of years, and the yearly interest rate in percent.*/
int main()
{
    float initial,years;
    float rate;
    printf("Enter initial amount: ");
    scanf("%f",&initial);
    printf("Enter number of years: ");
    scanf("%f",&years);
    printf("Enter interest rate (percent per year):");
    scanf("%f",&rate);
    for(int i=0;i<years;i++){
        initial=initial+initial*(rate/100);
    }
    printf("At the end of %.1f years, you will have %.3f dollars",years,initial);


    return 0;
}
