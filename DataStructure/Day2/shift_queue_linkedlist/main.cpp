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
class Queue{
node * tail;
node * head;

public:
    Queue(){
        tail=head=NULL;
    }
    void enqueue(int id,int age,char* name){
       node * temp=new node();
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
    void dequeue(){
        if(head!=NULL){
            node* temp=head;
            head=head->next;
            if(head==NULL)tail==NULL;
            cout<<temp->id<<":"<<temp->age<<":"<<temp->name<<endl;
            delete temp;
        }
        else {
            cout<<"Queue is Empty"<<endl;
        }

    }
    int isEmpty(){
        return (head==NULL);
    }
    void displayAll(){
         node * temp=head;
        while(temp!=NULL){
            cout<<temp->id<<":"<<temp->age<<":"<<temp->name<<endl;
            temp=temp->next;
        }
    }
    ~Queue(){
         node* temp=head;
        while(temp!=NULL){
            head=temp->next;
            delete temp;
            temp=head;
    }}
};
int main()
{
    Queue q;
    q.enqueue(1,10,"esraa");
    q.enqueue(2,20,"AML");
    q.enqueue(3,30,"Omar");
    q.enqueue(4,40,"Ahmed");
    cout<<"Display all Nodes"<<endl;
    q.displayAll();
    cout<<"printed 2 nodes with dequeue:"<<endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout<<"Display all Remaining Nodes"<<endl;
    q.displayAll();
    cout<<"print remaining nodes with dequeue:"<<endl;
    q.dequeue();
    q.dequeue();
    return 0;
}

