#include <stdio.h>
#include <stdlib.h>
struct emp{
    int id;
    char name[10];
    int age;
};
int main()
{
    struct emp e;
    struct emp *ptr=&e;
    printf("Enter Id,Name,Age:- \n");
    scanf("%d",&(ptr->id));
    scanf("%s",ptr->name);
    scanf("%d",&(ptr->age));
    printf("ID:-%d , Name:%s , Age:- %d",ptr->id,ptr->name,ptr->age);
    return 0;
}
