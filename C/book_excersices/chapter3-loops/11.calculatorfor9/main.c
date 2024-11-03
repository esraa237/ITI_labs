#include <stdio.h>
#include <stdlib.h>
/*Create a three-function calculator for old-style English currency, where money amounts
are specified in pounds, shillings, and pence. (See Exercises 10 and 12 in Chapter 2.)
The calculator should allow the user to add or subtract two money amounts, or to multiply a money amount by a floating-point number. (It doesn’t make sense to multiply two
money amounts; there is no such thing as square money. We’ll ignore division. Use the
general style of the ordinary four-function calculator in Exercise 4 in this chapter.)
*/
void add(int pounds1,int shillings1,int pence1,int pounds2,int shillings2,int pence2){
    unsigned pounds=0,shillings=0,pence=0;
    int ch1=156;
    pence=pence1+pence2;
    if(pence>=12){
        shillings=pence/12;
        pence%=12;
    }
    shillings+=shillings1+shillings2;
    if(shillings>=20){
        pounds=shillings/20;
        shillings%=20;
    }
    pounds+=pounds1+pounds2;
    printf("Total: %c%d.%d.%d",ch1,pounds,shillings,pence);
}
void sub(int pounds1,int shillings1,int pence1,int pounds2,int shillings2,int pence2){
    unsigned pounds=0,shillings=0,pence=0;
    int ch1=156;
    pence=pence1-pence2;
    if(pence>=12){
        shillings=pence/12;
        pence%=12;
    }
    shillings+=shillings1-shillings2;
    if(shillings>=20){
        pounds=shillings/20;
        shillings%=20;
    }
    pounds+=pounds1-pounds2;
    printf("Total: %c%d.%d.%d",ch1,pounds,shillings,pence);
}
void multiplay(int pounds1,int shillings1,int pence1,int num){
    unsigned pounds=0,shillings=0,pence=0;
    int ch1=156;
    pence=pence1*num;
    if(pence>=12){
        shillings=pence/12;
        pence%=12;
    }
    shillings+=shillings1*num;
    if(shillings>=20){
        pounds=shillings/20;
        shillings%=20;
    }
    pounds+=pounds1*num;
    printf("Total: %c%d.%d.%d",ch1,pounds,shillings,pence);
}

int main()
{
    unsigned int pounds1,shillings1,pence1,choice;
    unsigned int pounds2,shillings2,pence2;
    int ch1=156;
    char ch='y';
    int num;
    while(ch=='y'){
        printf("Enter the first amount: %c",ch1);
        scanf("%d.%d.%d",&pounds1,&shillings1,&pence1);
        printf("Enter 1 for add \nEnter 2 for sub \nEnter 3 for multiply:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the second amount: %c",ch1);
                scanf("%d.%d.%d",&pounds2,&shillings2,&pence2);
                add(pounds1,shillings1,pence1,pounds2,shillings2,pence2);
                break;
            case 2:
                printf("Enter the second amount: %c",ch1);
                scanf("%d.%d.%d",&pounds2,&shillings2,&pence2);
                sub(pounds1,shillings1,pence1,pounds2,shillings2,pence2);
                break;
            case 3:
                printf("Enter the number you want to multiplay for: ");
                scanf("%d",&num);
                multiplay(pounds1,shillings1,pence1,num);
                break;
            default:
                printf("Wrong character !!Enter from (1/2/3)");
                scanf("%d",&choice);
                break;
        }
        printf("\nDo you wish to continue (y/n)? ");
        _flushall();
        scanf("%c",&ch);
    }
    return 0;
}
