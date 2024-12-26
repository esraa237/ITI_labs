#include <iostream>
#include <string.h>
using namespace std;
struct node{
int age;
int id;
char name[10];
node* next;
node* prev;
};
class LL{
node* head;
node* tail;
public:
LL(){
    head=tail=NULL;
}
    void append(int age,int id,char* name){
        node* temp=new node();
        temp->id=id;
        temp->age=age;
        strcpy(temp->name,name);
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
    void display(){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->id<<":"<<temp->name<<":"<<temp->age;
            temp=temp->next;
        }
    }
};
int main()
{
    LL l1;
    l1.append(10,20,"esraa");
    l1.append(20,50,"esr");
    l1.display();
    return 0;
}
