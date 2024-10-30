#include <stdio.h>
#include <stdlib.h>
struct emp{
    int id;
    char name[10];
    int age;
};
int main()
{
    struct emp employess[3];
    for(int i=0;i<3;i++){
        printf("ID%d:-",i+1);
        scanf("%d",&employess[i].id);
        printf("Name%d:-",i+1);
        scanf("%s",employess[i].name);
        printf("Age%d:-",i+1);
        scanf("%d",&employess[i].age);
    }
    for(int i=0;i<3;i++){
        printf("For employee %d\nID:-%d , Name:-%s , Age:-%d\n",i+1,employess[i].id,employess[i].name,employess[i].age);
    }

    return 0;
}
