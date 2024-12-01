#include <iostream>
#include<string.h>
using namespace std;
class person{
    protected:
        int id;
        int age;
        char name[30];
    public:
        person(){
            id=0;
            age=0;
            strcpy(name,"no_name");
        }
        person(int _id){
            id=_id;
            age=0;
            strcpy(name,"no_name");
        }
        person(int _id,char* _name,int _age){
            id=_id;
            age=_age;
            strcpy(name,_name);
        }
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
        void setName(char* _name){
            strcpy(name,_name);
        }
        char* getName(){
            return name;
        }
        void printPerson(){
            cout<<endl<<"person: "<<id<<":"<<name<<":"<<age;
        }
};
class emp:public person{
int salary;
public:
    emp(){
        salary=0;
    }
    emp(int _id,char * _name,int _age,int _salary):person(_id,_name,_age){
        salary=_salary;
    }
    void setSalary(int _s){salary=_s;}
    int getSalary(){return salary;}
    void printEmp(){
        printPerson();
        cout<<":"<<salary<<endl;
    }
};
class student:public person{
int grade;
public:
    student(){
        grade=0;
    }
    student(int _id,char * _name,int _age,int _grade):person(_id,_name,_age){
        grade=_grade;
    }
    void setGrade(int _g){grade=_g;}
    int getGrade(){return grade;}
    void printStudent(){
        printPerson();
        cout<<":"<<grade<<endl;
    }

};
int main()
{
    person p1(10,"esraa",30);
    p1.printPerson();
    emp e1(20,"e",10,222233);
    e1.printEmp();
    student s1(50,"100",30,60);
    s1.printStudent();
    return 0;
}
