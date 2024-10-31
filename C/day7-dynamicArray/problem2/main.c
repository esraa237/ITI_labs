#include <stdio.h>
#include <stdlib.h>
struct emp{
int ID;
char name[10];
int age;
};

int main()
{
    int size;
    printf("Enter Size of array:- ");
    scanf("%d",&size);
    struct emp* employee=(struct emp*)malloc(size*sizeof(struct emp));
    if(employee!=NULL){
        for(int i=0;i<size;i++){
         printf("Enter ID for Employee %d:-",i+1);
         scanf("%d",&employee[i].ID);
         printf("Enter Name for Employee %d:-",i+1);
         scanf("%s",employee[i].name);
         printf("Enter Age for Employee %d:-",i+1);
         scanf("%d",&employee[i].age);
         printf("\n+++++++++++++++++++++++++++++++++++++++++++++\n");
        }
        for(int i=0;i<size;i++){
         printf("\nID for Employee %d:-%d",i+1,employee[i].ID);
         printf("\nName for Employee %d:-%s",i+1,employee[i].name);
         printf("\nAge for Employee %d:-%d",i+1,employee[i].age);
         printf("\n------------------------------------------------");
        }
    }
    return 0;
}
