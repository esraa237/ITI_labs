#include <iostream>

using namespace std;
class Complex{
int real;
int img;
public:
    void setReal(int _real){
        real=_real;
    }
    int getReal(){
        return real;
    }
    void setImg(int _img){
        img=_img;
    }
    int getImg(){
        return img;
    }
    void print(){
        if(img<0){
            cout<<real<<" - "<<img*(-1)<<" i \n";
        }
        else if(img>0){
            cout<<real<<" + "<<img<<" i \n";
        }
        else{
            cout<<real<<endl;
        }
    }
    //constructors
    Complex(){
        img=0;
        real=0;
    }
   Complex(int _real){
        img=0;
        real=_real;
   }
    Complex(int _real,int _img){
        img=_img;
        real=_real;
    }
    Complex operator+(Complex c1){
        Complex res;
        res.real=c1.real+real;
        res.img=c1.img+img;
        return res;
    }
    Complex operator+(int x){
        Complex res(x+real,img);
        return res;
    }
    friend Complex operator+(int x,Complex c);

    int operator==(Complex c){
        return(real==c.real&&img==c.img);
    }
    int operator!=(Complex c){
        return !(real==c.real&&img==c.img);
    }
    explicit operator int(){
        return real;
    }
    Complex operator++(){
        real++;
        return *this;
    }
    Complex operator++(int){
        Complex temp=*this;
        real++;
        return temp;
    }
};
    Complex operator+(int x,Complex c){
        Complex res(x+c.real,c.img);
        return res;
    }
int main()
{
    int real,img;
    Complex c1(40,30);
    Complex c2(50,10);
    cout<<"Complex1: ";
    c1.print();
    cout<<"Complex2: ";
    c2.print();
    Complex c3=c1+c2;
    cout<<"Addition from member function:\n";
    c3.print();
    Complex c4=c1+3;
    cout<<"Addition complex1+3:\n";
    c4.print();
    Complex c5=7+c1;
    cout<<"Addition 7+complex1:\n";
    c5.print();
    if(c1==c2)cout<<"Equal"<<endl;
    if(c1!=c2)cout<<"Not Equal"<<endl;
    int y=(int)c1;
    cout<<"Casting c1=  "<<y;
    cout<<"\nc1++: ";
    c1++.print();
    cout<<"c1 after last statement: ";
    c1.print();
    cout<<"++c2: ";
    (++c2).print();
    return 0;
}
