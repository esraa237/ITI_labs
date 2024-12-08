#include <iostream>

using namespace std;
class Queue{
int *arr;
int top;
int size;
public:
    Queue(int _size=5){
        size=_size;
        arr=new int[size];
        top=-1;
    }
    void enqueue(int d){
    if(top<size-1){
        top++;
        arr[top]=d;
    }
    else
        cout<<"Queue is full"<<endl;
    }
    int dequeue(int& d){
        if(top!=-1){
            d=arr[0];
            for(int i=0;i<top;i++){
                arr[i]=arr[i+1];
            }
            top--;
            return 1;
        }
        else{
            cout<<"Queue is empty"<<endl;
            return 0;
        }
    }
    int isEmpty(){
        return (top==-1);
    }
    int isFull(){
        return top==size-1;
    }
};
int main()
{
    Queue q;
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    //Extra (Queue is Full Now)
    q.enqueue(70);
    int x;
    if(q.dequeue(x)==1){
        cout<<x<<endl;
    }
    if(q.dequeue(x)==1){
        cout<<x<<endl;
    }
    if(q.dequeue(x)==1){
        cout<<x<<endl;
    }
    if(q.dequeue(x)==1){
        cout<<x<<endl;
    }
    if(q.dequeue(x)==1){
       cout<<x<<endl;
    }
    //Extra (Queue is empty Now)
    if(q.dequeue(x)==1){
        cout<<x<<endl;
    }
    return 0;
}
