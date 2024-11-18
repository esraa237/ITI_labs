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
};

void printComplex(Complex c){
    if(c.getImg()<0){
        cout<<c.getReal()<<" - "<<(c.getImg())*(-1)<<" i ";
    }
    else if(c.getImg()>0){
        cout<<c.getReal()<<" + "<<c.getImg()<<" i ";
    }
    else{
        cout<<c.getReal();
    }
}
int main()
{
    int real,img;
    Complex c1;
    cout<<"Enter Real and Imaginary parts for complex number : \n";
    cin>>real>>img;
    c1.setReal(real);
    c1.setImg(img);
    printComplex(c1);
    return 0;
}
