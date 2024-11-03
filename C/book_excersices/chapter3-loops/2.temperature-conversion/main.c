#include <stdio.h>
#include <stdlib.h>
/*Write a temperature-conversion program that gives the user the option of converting
Fahrenheit to Celsius or Celsius to Fahrenheit. Then carry out the conversion. Use
floating-point numbers*/
int main()
{
    int n;
    float temp_f=0,temp_c=0;
    printf("Type 1 to convert Fahrenheit to Celsius,\n2 to convert Celsius to Fahrenheit: ");
    scanf("%d",&n);
    if(n==1){
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f",&temp_f);
        temp_f=(temp_f-32)/1.8;
        printf("In Celsius that’s: %.4f",temp_f);
    }
    else if(n==2){
        printf("Enter temperature in Celsius: ");
        scanf("%f",&temp_c);
        printf("In Fahrenheit that’s: %.2f",((temp_c*1.8)+32));
    }

    return 0;
}
