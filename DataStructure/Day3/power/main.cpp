#include <iostream>

using namespace std;
int pow(int x,int y){
    if(y<1)return 1;
    return x*pow(x,--y);
}
int main()
{
    int x,y;
    cout << "Enter base and power :";
    cin>>x>>y;
    cout<<"Result: "<<pow(x,y);
    return 0;
}
