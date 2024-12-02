#include <stdio.h>
#include <stdlib.h>/jk
#include <windows.h>
#include<conio.h>
#include<string.h>
struct emp{
int ID;
char name[10];
int age;
};
void gotoxy(int x, int y)
{
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void textatrr(int i){
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);
}
void DisplayAll(struct emp* ptr,long int size){
    for(int i=0;i<size;i++){
        if(ptr[i].ID!=-1){
            printf("ID for Employee %d:-%d\n",i+1,ptr[i].ID);
            printf("Name for Employee %d:-%s\n",i+1,ptr[i].name);
            printf("Age for Employee %d:-%d\n",i+1,ptr[i].age);
            printf("------------------------------------------------\n");
        }
        else if(ptr[i].ID==-1){
            printf("There is no employee in index %d\n",i);
            printf("------------------------------------------------\n");
        }
    }
}
void DisplayByID(struct emp* ptr,long int size){
      int Id_available=0;
      int id;
      printf("Enter ID: ");
      scanf("%d",&id);
      for(int i=0;i<size;i++){
        if(ptr[i].ID!=-1&&ptr[i].ID==id){
            printf("ID for Employee %d:-%d\n",i+1,ptr[i].ID);
            printf("Name for Employee %d:-%s\n",i+1,ptr[i].name);
            printf("Age for Employee %d:-%d\n",i+1,ptr[i].age);
            Id_available=1;
            break;
        }
        }
        if(Id_available!=1){
            printf("There is no id like this");
        }
}
void DisplayByName(struct emp* ptr,long int size){
    int name_available=0;
      char name[15];
      printf("Enter name: ");
      scanf("%s",name);
      for(int i=0;i<size;i++){
        if(strcmp(ptr[i].name,name)==0){
            printf("ID for Employee %d:-%d\n",i+1,ptr[i].ID);
            printf("Name for Employee %d:-%s\n",i+1,ptr[i].name);
            printf("Age for Employee %d:-%d\n",i+1,ptr[i].age);
            name_available=1;
            break;
        }
    }
    if(name_available!=1){
        printf("There is no name like this");
    }
}
int main()
{
    char ch;
    int n=0;
    int flag=0;
    int name_available=0;
    char menu[5][20]={"New","DisplayAll","DisplayByID","DisplayByName","Exit"};
    long int size;
    printf("Enter The Number of Employees:- ");
    scanf("%d",&size);
    struct emp* ptr=(struct emp*)malloc(size*sizeof(struct emp));
    if(ptr!=NULL){
        for(int i=0;i<size;i++){
           ptr[i].ID=-1;
        }
    }
    do{
        system("cls");
        for(int i=0;i<5;i++){
            gotoxy(7,7+i);
            if(i==n) textatrr(0x30);
            _cprintf("%s",menu[i]);
            textatrr(0x07);
        }
        ch=_getch();
        switch(ch){
            case -32:
                ch=_getch();
                switch (ch){
                case 72:
                    n--;
                    if(n<0)n=4;
                    break;
                case 80:
                    n++;
                    if(n>4)n=0;
                    break;
                }
                break;
            case 13:
                system("cls");
                if(n==0){
                    int index;
                    printf("Enter index of the employee from 0 to %d:- ",size-1);
                    scanf("%d",&index);
                    printf("For index %d\n",index);
                    printf("Enter ID:- ");
                    scanf("%d",&ptr[index].ID);
                    printf("Enter Name:- ");
                    scanf("%s",ptr[index].name);
                    printf("Enter Age:- ");
                    scanf("%d",&ptr[index].age);
                    system("cls");
                }
                else if(n==1){
                    DisplayAll(ptr,size);
                    ch=_getch();
                }
                else if(n==2){
                  //scan id and compare it with ptr[i].id
                    DisplayByID(ptr,size);
                    ch=_getch();
                }
                else if(n==3){
                      //scan name and compare it with ptr[i].name
                    DisplayByName(ptr,size);
                    ch=_getch();
                }
                else if(n==4){
                    printf("Exit selected");
                    flag=1;
                }
                break;
            case 27:
                system("cls");
                printf("Escape Selected");
                flag=1;
                break;
        }
    }
    while(flag==0);
    return 0;
}
