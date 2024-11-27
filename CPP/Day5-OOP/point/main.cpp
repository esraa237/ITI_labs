#include <iostream>

using namespace std;
class Point{
int x;
int y;
public:
    void setX(int _x){
        x=_x;
    }
    int getX(){
        return x;
    }
    void setY(int _y){
        y=_y;
    }
    int getY(){
        return y;
    }
    Point(){
        x=0;
        y=0;
        cout<<"Point constructor\n";
    }
    Point(int _x){
        x=y=_x;
    }
    Point(int _x,int _y){
        x=_x;
        y=_y;
    }
    void print(){
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
    ~Point(){
        cout<<"point destructor"<<endl;
    }
};
class Rect{
Point UL;
Point LR;
public:
    Rect(){cout<<"Rect constructor\n";}
    Rect(Point _ul,Point _lr){
        UL=_ul;
        LR=_lr;
    }
    Rect(int _x1,int _y1,int _x2,int _y2):UL(_x1,_y2),LR(_x2,_y2){}
    void setUl(Point _UL){
        UL=_UL;
    }
    void setUl(int _x,int _y){
        UL.setX(_x);
        UL.setY(_y);
    }
    Point getUl(){
        return UL;
    }
    void setLr(Point _LR){
        LR=_LR;
        }
    void setLr(int _x,int _y){
        LR.setX(_x);
        LR.setY(_y);
    }
    Point getLr(){
        return LR;
    }
    ~Rect(){
        cout<<"Rect destructor"<<endl;
    }
    void print(){
        cout<<"Point1:";
        UL.print();
        cout<<"Point2:";
        LR.print();
    }
};
class Circle{
int raduis;
Point center;
public:
    Circle(){
        cout<<"circle constructor"<<endl;
    }
    Circle(int _r,Point c){
        raduis=_r;
        center=c;
    }
    Circle(int _r,int x1,int y1):center(x1,y1){
        raduis=_r;
    }
    void setCenter(int x1,int y1){
        center.setX(x1);
        center.setY(y1);
    }
    void setCenter(Point _c){
        center=_c;
    }
    Point getCenter(){
        return center;
    }
    void setRaduis(int r){
        raduis=r;
    }
    int getRaduis(){
        return raduis;
    }
    ~Circle(){
        cout<<"Circle Destructor"<<endl;
    }
    void print(){
        cout<<"Center:";
        center.print();
        cout<<"Radius: "<<raduis<<endl;
    }
};
int main()
{
    Point p1(10,20);
    p1.print();
    Point p2(30,40);
    p2.print();
    //Rect r1(p1,p2);
    //r1.print();
    Rect r2(1,3,4,5);
    r2.print();
    Circle c1(5,50,60);
    c1.print();
    return 0;
}
