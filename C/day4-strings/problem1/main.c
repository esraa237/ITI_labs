#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
   char f_name[15];
   char l_name[7];
   printf("Enter first name :- ");
   scanf("%s",f_name);
   printf("Enter last name :- ");
   scanf("%s",l_name);
   strcat(f_name," ");
   strcat(f_name,l_name);
   printf("Full Name: %s",f_name);

    return 0;
}
