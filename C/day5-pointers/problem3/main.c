#include <stdio.h>
#include <stdlib.h>

struct emp{
    char name[10];
    int age;
    int id;
};
int main()
{
    struct emp e1;
     printf("Enter Name:- ");
    scanf("%s",&(e1.name));
    printf("Enter id:- ");
    scanf("%d",&(e1.id));
     printf("Enter age:- ");
    scanf("%d",&(e1.age));
    printf("Name: %s\nAge: %d\nID: %d",e1.name,e1.age,e1.id);
    return 0;
}
