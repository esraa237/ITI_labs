#include <iostream>

using namespace std;
int fact(int d){
    if(d<=1){
        return 1;
    }
    else
        return d*fact(d-1);
}
int main()
{
    int num;
    cout<<"Enter the num: ";
    cin>>num;
    cout<<"factorial: "<<fact(num);
    return 0;
}
