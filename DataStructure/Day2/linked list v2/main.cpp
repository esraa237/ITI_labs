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
    int Count(){
        int c=0;
        node *temp=head;
        while(temp!=NULL){
            c++;
            temp=temp->next;
        }
        return c;
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
    ~LL(){
        node* temp=head;
        while(temp!=NULL){
            head=temp->next;
            delete temp;
            temp=head;
        }
    }
};
int main()
{
    LL l1;
    l1.append(10,20,"esraa");
    l1.append(20,50,"esr");
    l1.display();
    node res=l1.searchById(10);
    if(res.id!=-1){
            cout<<res.name<<":"<<res.age<<endl;
    }
    l1.insertbyId(30,40,"omar",30);
    l1.display();
    return 0;
}
