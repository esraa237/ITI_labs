#include <iostream>

using namespace std;
class Stack{
int tos;
int Size;
int *arr;
public:
    int getsize(){
        return Size;
    }
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
    /*Stack(Stack& s){
        Size=s.Size;
        tos=s.tos;
        arr=new int[Size];
        for(int i=0;i<Size;i++){
            arr[i]=s.arr[i];
        }
        cout<<"Copy constructor"<<endl;
    } //in pass by refrence  copy constructor won't called*/
    Stack& operator = (Stack& s){
        tos=s.tos;
        Size=s.Size;
        delete[] arr;
        arr=new int[Size];
        for(int i=0;i<=tos;i++)
            arr[i]=s.arr[i];
        return *this;
    }
    Stack& operator+(Stack s){
        Stack res;
        res.Size=s.Size+Size;
        res.tos=tos+s.tos+1;
        res.arr=new int[res.Size];
        for(int i=0;i<Size;i++){
            res.arr[i]=arr[i];
            cout<<"---"<<arr[i]<<endl;
        }
        for(int i=0;i<s.Size;i++){
            res.arr[Size+i]=s.arr[i];
            cout<<"===="<<s.arr[i]<<endl;
        }
        for(int i=0;i<res.Size;i++){
        cout<<res.arr[i]<<endl;
        }
        return res;
    }
    ~Stack(){
        delete[] arr;
        cout<<"Stack destroyed"<<endl;
    }
};
void viewContent(Stack& s2){
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
    Stack s1(3);
    s1.push(100);
    s1.push(200);
    s1.push(300);
   // Stack s1=s2;
   // viewContent(s1);
    Stack s3=s1+s2;
   // Stack s3;
 //   s3=s1+s2;
/*  cout<<"Before Function"<<endl;
    viewContent(s2);
    cout<<"Push value!!! \n";
    s2.push(900);//check s2 copy or not
    cout<<"pop after destroyed"<<endl;
    if(s2.pop(x)==1)//empty
        cout<<x<<endl;
    if(s2.pop(x)==1)
        cout<<x<<endl;
    if(s2.pop(x)==1)
    cout<<x<<endl;*/
    return 0;
}
