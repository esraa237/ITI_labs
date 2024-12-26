#include <iostream>

using namespace std;
struct node{
int id;
node * next;
node * prev;
};
class Queue{
node* head;
node* tail;
public:
    Queue(){
        head=tail=NULL;
    }
    void enqueue(int id){
        node* temp=new node();
        temp->id=id;
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
    int dequeue(){
        if(head!=NULL){
            node* temp=head;
            head=head->next;
            if(head==NULL)tail=NULL;
            return temp->id;
        }
    }

};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
