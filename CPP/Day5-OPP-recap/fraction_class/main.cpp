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
        if(num==0){
            cout<<num<<endl;
        }
        else if(den>1){
            cout<<num<<"/"<<den<<endl;
        }
        else if(den==1){
            cout<<num<<endl;
        }
        else if(den==0){
            cout<<"Invalid"<<endl;
        }
        else if(den<0){
            cout<<-1*num<<"/"<<den<<endl;
        }
    }
    void simplify(){
        int temp;
        if(num>=den)temp=num;
        else temp=den;
        for(int i=temp;i>1;i--){
            if(num%i==0&&den%i==0){
                num/=i;
                den/=i;
                break;
            }
        }
    }
    Fraction operator-(Fraction f){
        Fraction res(num*f.den-f.num*den,den*f.den);
        return res;
    }
    Fraction operator*(Fraction f){
        Fraction res(num*f.num,den*f.den);
        return res;
    }
    Fraction operator/(Fraction f){
        Fraction res(num*f.den,den*f.num);
        return res;
    }
    Fraction operator++(){
        Fraction res;
        res.num=num+den;
        res.den=den;
        res.simplify();
        return res;
    }
    Fraction operator--(){
        Fraction res;
        res.num=num-den;
        res.den=den;
        res.simplify();
        return res;
    }
    explicit operator float(){
        float res=float(num)/(float)den;
        return res;
    }
};
int main()
{
    int num,den;
    cout<<"Enter fraction numerator and denominator:- \n";
    cin>>num>>den;
    Fraction f1(num,den);
    f1.print();
    f1.simplify();
    f1.print();
    Fraction f2(1,2);
    f2.print();
    Fraction f3=f1-f2;
    f3.simplify();
    f3.print();
    Fraction f4=f1/f2;
    f4.simplify();
    f4.print();
    Fraction f5=++f1;
    f5.print();
    Fraction f6=--f1;
    f6.print();
    cout<<"Casting f1: "<<(float)f1;
    return 0;
}
