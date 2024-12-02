#include <iostream>

using namespace std;
class shape{
protected:
    int dim1;
    int dim2;
public:
    void setDim1(int _dim1){dim1=_dim1;}
    void setDim2(int _dim2){dim2=_dim2;}
    int getDim1(){return dim1;}
    int getDim2(){return dim2;}
    shape(){
        dim1=dim2=0;
    }
    shape(int _dim1){
        dim1=dim2=_dim1;
    }
    shape(int _dim1,int _dim2){
        dim1=_dim1;
        dim2=_dim2;
    }
    virtual float calcArea()=0;
};
class Rect:public shape{
public:
    Rect(int _dim1,int _dim2):shape(_dim1,_dim2){}
    Rect(int _dim1):shape(_dim1){}
    float calcArea(){
        return dim1*dim2;
    }
};
class Triangle:public shape{
public:
    Triangle(int _dim1,int _dim2):shape(_dim1,_dim2){}
    float calcArea(){
        return dim1*dim2*0.5;
    }
};
class circle:public shape{
public:
    circle(int _dim1):shape(_dim1){}
    float calcArea(){
        return 3.14*dim1*dim2;
    }
};
class square:public Rect{
public:
    square(int _dim1):Rect(_dim1){}
    float calcArea(){
        return dim1*dim1;
    }
};
float myfun(shape* s){
    return s->calcArea();
}
float myfun2(shape* *s,int size){
    float sum=0;
for(int i=0;i<size;i++){
    sum+= s[i]->calcArea();
}
return sum;
}
int main()
{
    Rect r1(10,20);
    cout<<r1.getDim1()<<","<<r1.getDim2()<<":"<<myfun(&r1)<<endl;
    circle c(10);
    cout<<c.getDim1()<<","<<c.getDim2()<<":"<<myfun(&c)<<endl;
    Triangle t1(20,5);
    cout<<t1.getDim1()<<","<<t1.getDim2()<<":"<<myfun(&t1)<<endl;
    square s1(10);
    cout<<s1.getDim1()<<","<<s1.getDim2()<<":"<<myfun(&s1)<<endl;
    shape* arr[4]={&r1,&c,&t1,&s1};
    cout<<myfun2(arr,4);

    return 0;
}
