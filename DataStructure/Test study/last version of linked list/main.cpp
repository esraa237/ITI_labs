#include <iostream>

using namespace std;
struct node{
int id;
char name[10];
int age;
node* prev;
node* next;
};
class LL{
node* head;
node* tail;
node* searchByIdPriv(int _id){
    node* res=head;
    while(res!=NULL){
        if(res->id==_id) return res;
        res=res->next;
    }
    return NULL;
}
public:
    LL(){
        head=tail=NULL;
    }
    void apppend(int _id,int _age,char* _name){
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
    node searchById(int id){
        node* resAd=searchByIdPriv(id);
        node res;
        if(resAd!=NULL){
            res.id=resAd->id;
            res.age=resAd->age;
            strcpy(res.name,resAd->name);
            res.next=res.prev=NULL;
        }
        else{
            res.id=-1;
        }
        return res;
    }
    int countNodes(){
        node* temp=head;
        int counter=0;
        while(temp!=NULL){
            counter++;
            temp=temp->next;
        }
        return counter;
    }
    void deleteById(int id){
        if(head==NULL)return;
        else{
        node* resAd=searchByIdPriv(id);
        if(resAd==NULL) return;
        else if(head==tail)head=tail=NULL;
        else if(resAd==tail){
            tail=tail->prev;
            tail->next=NULL;
        }
        else{
            resAd->prev->next=resAd->next;
            resAd->next->prev=resAd->prev;
        }
        }
    }
    void insertById(int id,int age,char* name,int existing_id){
        node* res=searchByIdPriv(existing_id);
        if(res==NULL)return;
        else if(res==tail||head==NULL){
                apppend(id,age,name);
        }
        else if(res==head){
            node* temp=new node();
            temp->id=id;
            temp->age=age;
            strcpy(temp->name,name);
            temp->next=res->next;
            temp->prev=res;
            res->next=temp;
            temp->next->prev=temp;
        }
    }

    LL& operator=(LL& l1){
        node* temp=head;
        node* tempc=l1.head;
        if(countNodes()==l1.countNodes()){
            while(tempc!=NULL){
            temp->id=tempc->id;
            temp->age=tempc->age;
            strcpy(temp->name,tempc->name);
            temp=temp->next;
            tempc=tempc->next;
        }}
        else if(countNodes()>l1.countNodes()){
            while(tempc!=NULL){
                temp->id=tempc->id;
                temp->age=tempc->age;
                strcpy(temp->name,tempc->name);
                temp=temp->next;
                tempc=tempc->next;
            }
            if(temp!=NULL){
                node* tempNext;
            while(temp!=NULL){
                tempNext=temp->next
                delete temp;
                temp=tempNext;
            }
            }
            head = NULL;
        }


        else
        {
            while (temp != NULL && tempc != NULL)
            {
                temp->age = tempc->age;
                temp->id = tempc->id;
                strcpy(temp->name, tempc->name);
                tempc = tempc->next;
                temp = temp->next;
            }

            // Append new nodes to the current list from the remaining nodes in the source list
            while (tempc != NULL)
            {
                append(tempc->id, tempc->name, tempc->age);
                tempc = tempc->next;
            }
        }
        return *this;
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
