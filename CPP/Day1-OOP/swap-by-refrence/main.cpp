#include <iostream>

using namespace std;
void swap(int& x,int& y){
    int temp=x;
    x=y;
    y=temp;
}
int main()
{
    int x,y;
    cout<<"Enter two numbers: ";
    cin>>x>>y;
    swap(x,y);
    cout<<"After swapping\nx: "<<x<<" , y: "<<y;
    return 0;
}
