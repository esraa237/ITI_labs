#include <iostream>

using namespace std;
class Queue{
int size;
int* arr;
int top;
public:
    Queue(int _size=5){
        size=_size;
        arr[size]=new int();
        top=-1;
    }
    void enqueue(int d){
        if(top<size-1){
            top++;
            arr[top]=d;
        }
        else cout<<"queue is full";
    }
    int dequeue(int& d){
        if(top!=-1){
            d=arr[0];
        for(int i=0;i<top;i++){arr[i]=arr[i+1];}
            top--;
            return 1;
        }
        else {
            cout<<"queue is empty";
            return 0;

    }

};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
