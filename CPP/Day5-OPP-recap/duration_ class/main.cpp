#include <iostream>

using namespace std;
class Duration{
int hours;
int minutes;
int seconds;
public:
    void setHours(int _hours){
        hours=_hours;
    }
    int getHours(){
        return hours;
    }
    void setMinutes(int _minutes){
        if(_minutes>59){
            hours+=_minutes/60;
            _minutes=_minutes%60;
        }
        minutes=_minutes;
    }
    int getMinutes(){
        return minutes;
    }
     void setSeconds(int _seconds){
         if(_seconds>3600){
            hours+=_seconds/(60*60);
            _seconds=_seconds%(60*60);
            minutes+=_seconds/60;
            _seconds=_seconds%60;
         }
         else if(_seconds>59){
             minutes+=_seconds/60;
            _seconds=_seconds%60;
         }
        seconds=_seconds;
    }
    int getSeconds(){
        return seconds;
    }
    Duration(int _hours,int _minutes,int _seconds){
        hours=_hours+_minutes/60+_seconds/(60*60);
        _minutes=_minutes%60;
        _seconds=_seconds%(60*60);
        minutes=_minutes+_seconds/60;
        seconds=_seconds%60;
    }
    Duration(int _seconds){
        hours=_seconds/(60*60);
        _seconds=_seconds%(60*60);
        minutes=_seconds/60;
        seconds=_seconds%60;
    }
    void print(){
        cout<<"Hours:"<<hours<<" ,Minutes:"<<minutes<<" ,Seconds:"<<seconds<<endl;
    }
    Duration operator+(Duration d){
        Duration res(hours+d.hours,minutes+d.minutes,seconds+d.seconds);
        return res;
    }
    Duration operator+(int s){
        Duration res(hours,minutes,s+seconds);
        return res;
    }
    Duration operator++(int){
        Duration temp(hours,minutes,seconds);
        minutes++;
        return temp;
    }
    Duration operator--(){
        minutes--;
        return *this;
    }
    int operator>(Duration d){
        seconds=hours*3600+minutes*60+seconds;
        d.seconds=(d.hours)*3600+(d.minutes)*60+d.seconds;
        if(seconds>d.seconds)
            return 1;
        else
            return 0;
    }
    int operator<=(Duration d){
        seconds=hours*3600+minutes*60+seconds;
        d.seconds=(d.hours)*3600+(d.minutes)*60+d.seconds;
        if(seconds<=d.seconds)
            return 1;
        else
            return 0;
    }

};
Duration operator+(int s,Duration d){
    Duration res(d.getHours(),d.getMinutes(),d.getSeconds()+s);
    return res;
}
int main()
{

    int h,m,s;
    cout<<"Enter The Duration Hours,minutes,seconds: ";
    cin>>h>>m>>s;
    Duration d1(h,m,s);
    d1.print();
    Duration d2(7800);
    d2.print();
    Duration d3=d1+d2;
    d3.print();
    Duration d4=d1+7800;
    d4.print();
    Duration d5=7800+d1+7800;
    d5.print();
    (d1++).print();
    d1.print();
    (--d2).print();
    if(d1>d2)
        cout<<"D1 is greater that D2"<<endl;
    else
        cout<<"D1 isn't greater that D2"<<endl;
    if(d2<=d3)
        cout<<"D2 <= D3"<<endl;
    else
        cout<<"D2 > D3"<<endl;
    return 0;
}
