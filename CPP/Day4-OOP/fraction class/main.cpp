#include <iostream>

using namespace std;
class Fraction{
int num;
int den;
public:
    Fraction(){
        num=0;
        den=0;
    }
    Fraction(int _num){
        num=_num;
        den=0;
    }
    Fraction(int _num,int _den){
        num=_num;
        den=_den;
    }
    void setNum(int _num){
        num=_num;
    }
    int getNum(){
        return num;
    }
    void setDen(int _den){
        den=_den;
    }
    int getDen(){
        return den;
    }
    void print(){
        int res=num/den;
        if(den>1){
            cout<<num<<"/"<<den<<":"<<endl;
        }
        else if(den==1){
            cout<<num<<endl;
        }
        else if(den==0){
            cout<<"Invalid denominator"<<endl;
        }
        else if(den<0){
            cout<<-1*num<<"/"<<den<<endl;
        }
    }
};
int main()
{
    int num,den;
    cout<<"Enter fraction numerator and denominator:- \n";
    cin>>num>>den;
    Fraction f1(num,den);
    f1.print();
    return 0;
}
