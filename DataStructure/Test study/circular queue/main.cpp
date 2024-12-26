#include <iostream>

using namespace std;
class Queue{
int size;
int* arr;
int rear;
int front;
public:
    Queue(int _size=5){
        size=_size;
        front=rear=-1;
        arr=new int[size];
    }
    int isFull(){
        return(rear=size-1&&front=0)||front=rear+1;
    }
    int isEmpty(){
        return rear==-1;
    }
    void enqueue(int d){
        if(isFull()!=1){
            if(rear==-1)front=rear=0;
            else if(rear==size-1)rear=0;
            else rear++;
            arr[rear]=d;
        }
        else return;
    }
    int dequeue(int& d){
        d=arr[front];
        if(front==rear)rear=front=-1;
        else if(front==size-1)front=0;
        else front++;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
