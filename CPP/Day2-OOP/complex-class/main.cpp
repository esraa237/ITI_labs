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
    Complex Add(Complex c1){
        Complex res;
        res.real=c1.real+real;
        res.img=c1.img+img;
        return res;
    }
};
Complex ADD(Complex c1,Complex c2){
    Complex res;
    res.setReal(c1.getReal()+c2.getReal());
    res.setImg(c1.getImg()+c2.getImg());
    return res;
}
int main()
{
    int real,img;
    cout<<"Enter Real and Imaginary parts for the first complex number : \n";
    cin>>real>>img;
    Complex c1(real,img);
    cout<<"Enter Real and Imaginary parts for the second complex number : \n";
    cin>>real>>img;
    Complex c2(real,img);
    cout<<endl;
    c1.print();
    c2.print();
    Complex c3=c1.Add(c2);
    cout<<"Addition from member function:\n";
    c3.print();
    Complex c4=ADD(c1,c2);
    cout<<"Addition from stand-alone function:\n";
    c4.print();
    return 0;
}
