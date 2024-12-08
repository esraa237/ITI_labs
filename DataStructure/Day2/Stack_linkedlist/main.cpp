#include <iostream>

using namespace std;
struct node{
int id;
node * next;
node * prev;
};
class Stack{
node* head;
node* tail;
public:

    Stack(){
        head=tail=NULL;
    }

    void push(int x){
        node* temp=new node();
        temp->id=x;
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

    int pop(int& d){
        if(head!=NULL){
            d=tail->id;
            tail=tail->prev;
            if(tail==NULL)head=NULL;
            return 1;
        }
        else{
            cout<<"Stack is empty"<<endl;
            return 0;
        }
    }
};

int main()
{
    int x;
    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(60);
    if(s1.pop(x)==1)
        cout<<x<<endl;
    if(s1.pop(x)==1)
        cout<<x<<endl;
    if(s1.pop(x)==1)
        cout<<x<<endl;
    if(s1.pop(x)==1)
        cout<<x<<endl;
    if(s1.pop(x)==1)
        cout<<x<<endl;
    if(s1.pop(x)==1)
        cout<<x<<endl;
        if(s1.pop(x)==1)
        cout<<x<<endl;
    return 0;
}
