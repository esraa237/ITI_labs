#include <iostream>

using namespace std;
class Stack{
int tos;
int Size;
int *arr;
public:

    Stack(){
        Size=5;
        tos=-1;
        arr=new int[Size];
        cout<<"parameterless constructor"<<endl;
    }
    Stack(int s){
        tos=-1;
        Size=s;
        arr=new int[Size];
        cout<<"parameter \"size\" constructor"<<endl;
    }

    void push(int x){
        if(tos<Size-1){
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
    Stack(Stack& s){
        Size=s.Size;
        tos=s.tos;
        arr=new int[Size];
        for(int i=0;i<Size;i++){
            arr[i]=s.arr[i];
        }
        cout<<"Copy constructor"<<endl;
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
    cout<<"Before Function"<<endl;
    viewContent(s2);
    cout<<"Push value!! \n";
    s2.push(900);//check s2 copy or not
    cout<<"pop after destroyed"<<endl;
    if(s2.pop(x)==1)//empty
        cout<<x<<endl;
    if(s2.pop(x)==1)
        cout<<x<<endl;
    if(s2.pop(x)==1)
    cout<<x<<endl;
    return 0;
}
