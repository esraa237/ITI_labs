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
node * searchByIdPriv(int id){
        node * temp=head;
        while(temp!=NULL){
            if(id==temp->id){
                return temp;
            }
            temp=temp->next;
        }
        return NULL;
    }
node * searchByNamePriv(char * name){
        node * temp=head;
        while(temp!=NULL){
            if(strcmp(name,temp->name)){
                return temp;
            }
            temp=temp->next;
        }
        return NULL;
    }
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
            cout<<"ID for Employee:"<<temp->id<<endl;
            cout<<"Name for Employee:"<<temp->name<<endl;
            cout<<"Age for Employee:"<<temp->age<<endl;
            cout<"-------------------------------------------\n";
            temp=temp->next;
        }
    }
    int Count(){
        int c=0;
        node *temp=head;
        while(temp!=NULL){
            c++;
            temp=temp->next;
        }
        return c;
    }
     node searchById(int id){
        node * resad=searchByIdPriv(id);
        node res;
        if(resad!=NULL){
            res.next=NULL;
            res.prev=NULL;
            res.id=resad->id;
            res.age=resad->age;
            strcpy(res.name,resad->name);
        }
        else{
            res.id=-1;
        }
        return res;
    }

 node searchByName(char* name){
        node * resad=searchByNamePriv(name);
        node res;
        if(resad!=NULL){
            res.next=NULL;
            res.prev=NULL;
            res.id=resad->id;
            res.age=resad->age;
            strcpy(res.name,resad->name);
        }
        else{
            strcpy(res.name,"NoName");
        }
        return res;
    }
 void insertbyId(int id,int age,char* name,int ex_id){
        if(head==NULL){
            append(id,age,name);
            return;
        }
        node* res=searchByIdPriv(ex_id);
        if(res!=NULL){
            node * temp=new node();
            temp->id=id;
            temp->age=age;
            strcpy(temp->name,name);
            if(res==head){
                temp->next=head;
                temp->prev=NULL;
                head=temp;
                res->prev=temp;
            }
            else{
                temp->next=res;
                temp->prev=res->prev;
                res->prev=temp;
                temp->prev->next=temp;
            }
        }
        else{
            cout<<"there is no id like this"<<endl;
        }
    }
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
int main()
{
    char ch;
    int n=0;
    int flag=0;
    int name_available=0;
    char menu[6][20]={"New","DisplayAll","DisplayByID","DisplayByName","New before id","Exit"};
    LL l1;
    do{
        system("cls");
        for(int i=0;i<6;i++){
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
                    if(n<0)n=5;
                    break;
                case 80:
                    n++;
                    if(n>5)n=0;
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
                    cout<<"Number Of Employees:"<<l1.Count()<<endl;
                    l1.displayAll();
                    ch=_getch();
                }
                else if(n==2){
                  //scan id and compare it with ptr[i].id
                    int id;
                    cout<<"Enter ID: "<<endl;
                    cin>>id;
                    node res=l1.searchById(id);
                    if(res.id!=-1){
                        cout<<"Name:"<<res.name<<endl;
                        cout<<"Age:"<<res.age<<endl;
                    }
                    else{
                        cout<<"There is no id like this";
                    }
                    ch=_getch();
                }
                else if(n==3){
                      //scan name and compare it with ptr[i].name
                      char name[15];
                      cout<<"Enter name: ";
                      cin>>name;
                      node res=l1.searchByName(name);
                      if(strcmp(res.name,"NoName")){
                        cout<<"There is no name like this";
                      }
                    else{
                        cout<<"ID:"<<res.id<<endl;
                        cout<<"Age:"<<res.age<<endl;
                    }
                      ch=_getch();
                }
                else if(n==4){
                    int id;
                    int id1,age;
                    char name[10];
                    cout<<"Enter ID you want to insert before: "<<endl;
                    cin>>id;
                    cout<<"Enter ID:- ";
                    cin>>id1;
                    cout<<"Enter Name:- ";
                    cin>>name;
                    cout<<"Enter Age:- ";
                    cin>>age;
                    l1.insertbyId(id1,age,name,id);
                }
                else if(n==5){
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
