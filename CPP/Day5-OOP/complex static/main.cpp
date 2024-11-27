#include <iostream>

using namespace std;
class Complex{
int real;
int img;
static int counter;
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
     static int getCounter(){
        return counter;
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
        counter++;
    }
   Complex(int _real){
        img=0;
        real=_real;
        counter++;
   }
    Complex(int _real,int _img){
        img=_img;
        real=_real;
        counter++;
    }
    ~Complex(){
        counter--;
        cout<<"object deleted"<<endl;
        cout<<counter<<endl;
    }
};
int Complex::counter=0;
int main()
{
    int real,img;
    Complex c1(40,30);
    Complex c2(50,10);
    cout<<"Complex1: ";
    c1.print();
    cout<<"Complex2: ";
    c2.print();
    cout<<Complex::getCounter()<<endl;
    return 0;
}
