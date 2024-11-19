#include <iostream>

using namespace std;
class Stack{
int tos;
int size;
int *arr;
public:

    Stack(){
        size=5;
        tos=-1;
        arr=new int[size];
        cout<<"parameterless constructor"<<endl;
    }
    Stack(int s){
        tos=-1;
        size=s;
        arr=new int[size];
        cout<<"parameter \"size\" constructor"<<endl;
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
    ~Stack(){
        delete[] arr;
        cout<<"Stack destroyed"<<endl;
    }
};
void viewContent(Stack s2){
    int x;
    cout <<"in function"<<endl;
    if(s2.pop(x)==1)
        cout<<x<<endl;
    if(s2.pop(x)==1)
        cout<<x<<endl;
    if(s2.pop(x)==1)
        cout<<x<<endl;
    cout<<"finish function"<<endl;
}
int main()
{
    int x;
    Stack s2(3);
    s2.push(100);
    s2.push(200);
    s2.push(300);
    s2.push(400);//full
    viewContent(s2);
    s2.push(900);//check s2 copy or not
    cout<<"Push finish\npop after destroyed"<<endl;
    if(s2.pop(x)==1)//empty
        cout<<x<<endl;
    if(s2.pop(x)==1)
        cout<<x<<endl;
    if(s2.pop(x)==1)
        cout<<x<<endl;
    return 0;
}
