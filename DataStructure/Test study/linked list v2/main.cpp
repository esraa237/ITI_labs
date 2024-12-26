#include <iostream>

using namespace std;
struct node{
int id;
int age;
char name[10];
node* prev;
node* next;
};
class LL{
node* head;
node* tail;
node* searchByIdPriv(int _id){
    node* temp=head;
    while(temp!=NULL){
        if(temp->id==id)return temp;
        temp=temp->next;
    }
    return NULL;
}
public:
LL(){
tail=head=NULL;
}
void insertById(int _id,int _age,char* _name,int existingId){
    node* res=
    if(existingId==tail.id)
        append(_id,_age,_name);
    else if(head==NULL)
        append


}
void append(int _id,int _age,char* _name){
    node* temp=new node();
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
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->id<<":"<<temp->name<<":"<<temp->age<<endl;
        temp=temp->next;
    }
}
int countNodes(){
    int counter=0;
    node* temp=head;
    while(temp!=NULL){
        counter++;
        temp=temp->next;
    }
    return counter;
}
node searchById(int _id){
    node* resAddress=searchByIdPriv(_id);
    node res;
    if(resAddress!=NULL){
        res.id=resAddress->id;
        res.age=resAddress->age;
        strcpy(res.name,resAddress->name);
        res.prev=res.next=NULL;
    }
    else res.id=-1;
    return res;
}
void deleteById(int _id){
    node* res=searchByIdPriv(_id);
    if(res==NULL) return;
    if(head==tail)head=tail=NULL;
    else if(head==res){
        head->next->prev=NULL;
        head=head->next;
    }
    else if(tail==res){
        tail=tail->prev;
        tail->next=NULL;
    }
    else{
        res->next->prev=res->prev;
        res->prev->next=res->next;
    }
}

~LL(){
    node* temp=head;
    while(temp!=NULL){
        head=head->next;
        delete temp;
        temp=head;
    }
}
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
