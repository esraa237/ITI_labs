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
    emp(int _id,char* _name){
        id=_id;
        strcpy(name,_name);
        age=30;
        cout<<"no age constructor\n";
    }
     emp(int _age,int _id,char* _name){
        age=_age;
        id=_id;
        strcpy(name,_name);
        cout<<"3 parameter constructor\n";
    }
    ~emp(){
        cout<<"object destroyed\n";
    }
};
int main()
{
   int id,age;
    char name[10];
    emp e1(2,"esraa");
    cout<<"ID: "<<e1.getId()<<endl<<"Name: "<<e1.getName()<<endl<<"Age: "<<e1.getAge()<<endl;
    cout<<"Enter your Id,Name,Age: "<<endl;
    cin>>id>>name>>age;
    emp e2(age,id,name);
    cout<<"ID: "<<e2.getId()<<endl<<"Name: "<<e2.getName()<<endl<<"Age: "<<e2.getAge()<<endl;
    return 0;
}
