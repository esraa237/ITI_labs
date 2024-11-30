#include <iostream>
#include <string.h>
using namespace std;
class String{
    char* arr;
    int Size;
public:
    String(){
        Size=10;
        arr=new char[Size];
    }
    String(int x){
        Size=x;
        arr=new char[Size];
    }
    String(char* name){
        Size=strlen(name)+10;
        arr=new char[Size];
        strcpy(arr,name);
    }
    void setString(char* name){
        strcpy(arr,name);
    }
    char* getString(){
        return arr;
    }
    String(const String& s){
        Size=s.Size;
        arr=new char[Size];
        for(int i=0;i<Size;i++){
            arr[i]=s.arr[i];
        }
        cout<<"Copy constructor"<<endl;
    }
    String operator=(String &s){
        Size=s.Size;
        delete[] arr;
        arr=new char[Size];
        for(int i=0;i<=Size;i++)
            arr[i]=s.arr[i];
        return *this;
    }
    String operator+(String s){
        String res;
        strcpy(res.arr,"");
        res.Size=Size+s.Size;
        strcat(res.arr,arr);
        strcat(res.arr,s.arr);
        return res;
    }
    ~String(){
        delete[] arr;
    }
};
void viewContent(String s){
    cout<<s.getString();
}
int main()
{
    String s1;
    String s2(20);
    String s3("ahmed");
    cout<<"before function: \n";
    viewContent(s3);
    String s4("aly");
    String s5=s3+s4;
    viewContent(s5);
    String s6=s4;
    viewContent(s6);
    return 0;
}
