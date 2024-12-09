#include <iostream>

using namespace std;
class Queue{
int rear;
int front;
int size;
int* arr;
public:
    Queue(int _size=5){
        front=rear=-1;
        size=_size;
        arr=new int[size];
    }
    int isEmpty(){
        return(rear==-1);
    }
    int isFull(){
        return((front==rear+1)||(front==0&&rear==size-1));
    }
    void enQueue(int d){
        if(isFull()==1){
            cout<<"the queue is full"<<endl;
            return;
        }
        if(rear==-1){
            front=rear=0;
        }
        else if(rear==size-1){
            rear=0;
        }
        else
            rear++;
        arr[rear]=d;
    }
    int deQueue(int &d){
        if(isEmpty()==1){
            cout<<"the queue is empty"<<endl;
            return 0;
        }
        d=arr[front];
         if(rear==front){
            rear=front=-1;
            }
        else if(front==size-1){
            front=0;
        }
        else
            front++;
        return 1;
    }
};

int main()
{
    Queue q;
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    int d;
    if(q.deQueue(d)!=0)
        cout<<d<<endl;
    if(q.deQueue(d)!=0)
        cout<<d<<endl;
    if(q.deQueue(d)!=0)
        cout<<d<<endl;
    if(q.deQueue(d)!=0)
        cout<<d<<endl;
    if(q.deQueue(d)!=0)
        cout<<d<<endl;
    if(q.deQueue(d)!=0)
        cout<<d<<endl;

    return 0;
}
