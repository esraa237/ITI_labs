#include <stdio.h>
#include <stdlib.h>
/*Start with the fraction-adding program of Exercise 9 in Chapter 2, “C++ Programming
Basics.” This program stores the numerator and denominator of two fractions before
adding them, and may also store the answer, which is also a fraction. Modify the program so that all fractions are stored in variables of type struct fraction, whose two
members are the fraction’s numerator and denominator (both type int). All fractionrelated data should be stored in structures of this type.
*/
struct fraction{
int denominator;
int numerator;
};
int main()
{
    struct fraction fr1;
    struct fraction fr2;
    printf("Enter fraction1 in format num/num2: ");
    scanf("%d/%d",&fr1.numerator,&fr1.denominator);
    printf("Enter fraction2 in format num/num2: ");
    scanf("%d/%d",&fr2.numerator,&fr2.denominator);
    int result=(fr1.numerator*fr2.denominator + fr1.denominator*fr2.numerator) / (fr1.denominator*fr2.denominator);
    printf("Addition: %d/%d + %d/%d : %d/%d",fr1.numerator,fr1.denominator,fr2.numerator,fr2.denominator,(fr1.numerator*fr2.denominator + fr1.denominator*fr2.numerator),(fr1.denominator*fr2.denominator));
    return 0;
}
