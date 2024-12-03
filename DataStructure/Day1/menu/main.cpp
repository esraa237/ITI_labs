#include <iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
struct node{
int id;
int age;
char name[10];
node * next;
node * prev;
};
class LL{
node * tail;
node * head;
public:
    LL(){
        tail=head=NULL;
    }
    void append(int _id,int _age,char *_name){
        node * temp=new node();
        temp->id=_id;
        temp->age=_age;
        strcpy(temp->name,_name);
        temp->next=NULL;
        if(head==NULL){
            temp->prev=NULL;
            head=tail=temp;
        }
        else{
            temp->prev=tail;
            tail->next=temp;
            tail=temp;
        }
    }
    void displayAll(){
        node * temp=head;
        while(temp!=NULL){
            cout<<temp->id<<":"<<temp->age<<":"<<temp->name<<endl;
            temp=temp->next;
        }
    }
};
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
void DisplayByID(struct emp* ptr,long int size){
      int Id_available=0;
      int id;
      cout<<"Enter ID: "<<endl;
      cin>>id;
      for(int i=0;i<size;i++){
        if(ptr[i].ID!=-1&&ptr[i].ID==id){
            cout<<"ID for Employee:"<<i+1<<ptr[i].ID<<endl;
            cout<<"Name for Employee:"<<i+1<<ptr[i].name<<endl;
            cout<<"Age for Employee:"<<i+1<<ptr[i].age<<endl;
            Id_available=1;
            break;
        }
        }
        if(Id_available!=1){
            cout<<"There is no id like this";
        }
}
void DisplayByName(struct emp* ptr,long int size){
    int name_available=0;
      char name[15];
      cout<<"Enter name: ";
      cin>>name;
      for(int i=0;i<size;i++){
        if(strcmp(ptr[i].name,name)==0){
            cout<<"ID for Employee"<<i+1<<":"<<ptr[i].ID<<endl;
            cout<<"Name for Employee"<<i+1<<":"<<ptr[i].name<<endl;
            cout<<"Age for Employee"<<i+1<<":"<<ptr[i].age<<endl;
            name_available=1;
            break;
        }
    }
    if(name_available!=1){
        cout<<"There is no name like this";
    }
}
int main()
{
    char ch;
    int n=0;
    int flag=0;
    int name_available=0;
    char menu[5][20]={"New","DisplayAll","DisplayByID","DisplayByName","Exit"};
    LL l1;
 /*   long int size;
    cout<<"Enter The Number of Employees:- ";
    cin>>size;
    struct emp* ptr=(struct emp*)malloc(size*sizeof(struct emp));
    if(ptr!=NULL){
        for(int i=0;i<size;i++){
           ptr[i].ID=-1;
        }
    }*/
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
                    int id,age;
                    char name[10];
                    cout<<"Enter ID:- ";
                    cin>>id;
                    cout<<"Enter Name:- ";
                    cin>>name;
                    cout<<"Enter Age:- ";
                    cin>>age;
                    l1.append(id,age,name);
                    system("cls");
                }
                else if(n==1){
                    l1.displayAll();
                    ch=_getch();
                }
                else if(n==2){
                  //scan id and compare it with ptr[i].id
                   // DisplayByID(ptr,size);
                    ch=_getch();
                }
                else if(n==3){
                      //scan name and compare it with ptr[i].name
                   // DisplayByName(ptr,size);
                    ch=_getch();
                }
                else if(n==4){
                    cout<<"Exit selected";
                    flag=1;
                }
                break;
            case 27:
                system("cls");
                cout<<"Escape Selected";
                flag=1;
                break;
        }
    }
    while(flag==0);
    return 0;
}
