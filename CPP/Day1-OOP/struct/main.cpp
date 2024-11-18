#include <iostream>

using namespace std;
struct emp{
int id;
char name[10];
int age;
};
int main()
{
    emp e1;
    emp* ptr=&e1;
    cout<<"Enter your Id,Name,Age: "<<endl;
    cin>>ptr->id>>ptr->name>>ptr->age;
    cout<<"ID: "<<ptr->id<<endl<<"Name: "<<ptr->name<<endl<<"Age: "<<ptr->age;
    return 0;
}
