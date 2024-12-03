#include <iostream>
#include<string.h>
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
    void display(){
        node * temp=head;
        while(temp!=NULL){
            cout<<temp->id<<":"<<temp->age<<":"<<temp->name<<endl;
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
