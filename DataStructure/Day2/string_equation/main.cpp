#include <iostream>
#include<string.h>
using namespace std;

class NumStack{
int tos;
int size;
int arr[10];
public:
    NumStack(){
        size=8;
        tos=-1;
    }

    void push(int x){
        if(tos<size-1){
            tos++;
            arr[tos]=x;
        }
        else{
            cout<<"Stack is full"<<endl;
        }
    }
    void pop(int& d){
        if(tos!=-1){
            d=arr[tos];
            tos--;
        }
        else{
            cout<<"Stack is empty"<<endl;
        }
    }
    int isEmpty(){
        return(tos==-1);
    }
    int top(){
        if(tos!=-1){
            return arr[tos];
        }
    }
};
class OpStack{
int tos;
int size;
char arr[10];
public:

    OpStack(){
        size=8;
        tos=-1;
    }

    void push(char x){
        if(tos<size-1){
            tos++;
            arr[tos]=x;
        }
        else{
            cout<<"Stack is full"<<endl;
        }
    }
    void pop(char& d){
        if(tos!=-1){
            d=arr[tos];
            tos--;
        }
        else{
            cout<<"Stack is empty"<<endl;
        }
    }
    int isEmpty(){
        return(tos==-1);
    }
    char top(){
        if(tos!=-1){
            return arr[tos];
        }
    }

};
int prec(char op){
    if(op=='*'||op=='/'){
        return 2;
    }
    else if(op=='-'||op=='+'){
        return 1;
    }
};
void process(NumStack &nums,OpStack& op){
       int num1,num2;
       char ch;
       nums.pop(num2);
       nums.pop(num1);
       op.pop(ch);
       switch(ch){
            case '*':
                nums.push(num1*num2);
                break;
            case '/':
                nums.push(num1/num2);
                break;
            case '+':
                nums.push(num1+num2);
                break;
            case '-':
                nums.push(num1-num2);
                break;
       }
}
int main()
{   int res;
    char equation[30];
    OpStack op;
    NumStack nums;
    cout<<"Enter equation:"<<endl;
    cin>>equation;
    int i=0;
    while(equation[i]!= '\0'){
        if(equation[i]>='0'&&equation[i]<='9'){
            nums.push(equation[i]-'0');
        }
        else{
            if(op.isEmpty()==1){
                op.push(equation[i]);
            }
            else{
                        if(prec(equation[i])>= prec(op.top())){
                            op.push(equation[i]);
                        }
                        else{
                             while(op.isEmpty()!=1&&prec(equation[i])< prec(op.top())){
                              process(nums,op);
                        }op.push(equation[i]);
                }
            }
        }
        i++;
        }
        while(!op.isEmpty()){
            process(nums,op);
        }
        nums.pop(res);
        cout<<res<<endl;
        return 0;
}
