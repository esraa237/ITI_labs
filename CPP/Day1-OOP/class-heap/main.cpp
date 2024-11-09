#include <iostream>
#include<string.h>

using namespace std;
class emp{
int id;
char name[10];
int age;
public:
    void setId(int _id){
        id=_id;
    }
    int getId(){
        return id;
    }
    void setAge(int _age){
        age=_age;
    }
    int getAge(){
        return age;
    }
    void setName(char _name[]){
        strcpy(name,_name);
    }
    char* getName(){
        return name;
    }
};
int main()
{
    int id,age;
    char name[10];
    emp e1;
    emp* ptr=new emp;
    if(ptr!=NULL){
    cout<<"Enter your Id,Name,Age: "<<endl;
    cin>>id>>name>>age;
    ptr->setId(id);
    ptr->setName(name);
    ptr->setAge(age);
    cout<<"ID: "<<ptr->getId()<<endl<<"Name: "<<ptr->getName()<<endl<<"Age: "<<ptr->getAge();
    }
    delete[] ptr;
    return 0;
}
