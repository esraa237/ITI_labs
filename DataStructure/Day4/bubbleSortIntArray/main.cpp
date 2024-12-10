#include <iostream>

using namespace std;
void swap(int& x,int& y){
    int temp=x;
    x=y;
    y=temp;
};
void bubbleSort(int arr[],int size){
    int swapped;
    for(int i=1;i<size;i++){
        swapped=0;
        for(int j=0;j<size-i;j++){
            if(arr[j]>arr[j+1]){
              swap(arr[j],arr[j+1]);
              swapped=1;
            }
        }
        if(!swapped){
            break;
        }
    }
};
int main()
{
    int arr[5]={2,9,6,4,3};
    bubbleSort(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}
