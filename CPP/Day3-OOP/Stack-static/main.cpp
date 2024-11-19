#include <iostream>

using namespace std;
class Stack{
int tos;
int size;
int arr[5];
public:

    Stack(){
        size=5;
        tos=-1;
    }

    void push(int x){
        if(tos<size-1){
            tos++;
            arr[tos]=x;
        }
        else{
            cout<<"Stack is full"<<endl;
        }
    }

    int pop(int& d){
        if(tos!=-1){
            d=arr[tos];
            tos--;
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
    s1.push(60);//full
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
