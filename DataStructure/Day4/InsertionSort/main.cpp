#include <iostream>

using namespace std;
void swap(int& x,int& y){
    int temp=x;
    x=y;
    y=temp;
};
void insertionSort(int* arr,int size){
    int value,j;
    for(int i=1;i<size;i++){
            value=arr[i];//i for unsorded list
            j=i-1;
            while(j>=0&&arr[j]>value){
                arr[j+1]=arr[j];
                j=j-1;
            }
            arr[j+1]=value;
    }
}
int main()
{
    int arr[5]={2,9,6,4,3};
    insertionSort(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}
