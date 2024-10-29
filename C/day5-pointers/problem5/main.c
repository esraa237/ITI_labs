#include <stdio.h>
#include <stdlib.h>

struct complex{
int real;
int img;
};
int main()
{
    struct complex c1;
    printf("Real part: \n");
    scanf("%d",&(c1.real));
    printf("Imaginary part: \n");
    scanf("%d",&(c1.img));
    printf("Complex Number : ");
    if(c1.img<0){
        printf("%d - %d i",c1.real,-1*c1.img);
    }
    else if(c1.img==0){
        printf("%d",c1.real);
    }
    else{
        printf("%d + %d i",c1.real,c1.img);
    }

    return 0;
}
