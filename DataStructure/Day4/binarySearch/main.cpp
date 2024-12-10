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
int binarySearch(int* arr,int target,int size){
    bubbleSort(arr,size);
    int low=0;
    int high=size-1;
    int mid;
while(low<=high){
    mid=(high+low)/2;
    if(target==arr[mid])
        return mid;
    else if(arr[mid]<target)
        low=mid+1;
    else
        high=mid-1;
}
return -1;
}
int recBinarySearch(int* arr,int high,int low,int target){
    if(low>high){
        return -1;
    }
    int mid=(high+low)/2;
    if(arr[mid]==target)return mid;
    else if(arr[mid]<target)return recBinarySearch(arr,high,mid+1,target);
    else return recBinarySearch(arr,mid-1,low,target);
}
int main()
{   int arr[5]={5,24,60,16,7};
    int index_1=binarySearch(arr,60,5);
    cout<<"Binary search without recursion"<<endl;
    if(index_1!=-1){
        cout<<arr[index_1]<<" exists in index : "<<index_1<<endl;
    }
    else{
        cout<<"Not exist"<<endl;
    }

    cout<<"Binary search with recursion"<<endl;
    int index_2=binarySearch(arr,7,5);
    if(index_2!=-1){
        cout<<arr[index_2]<<" exists in index : "<<index_2<<endl;
    }
    else{
        cout<<"Not exist"<<endl;
    }

    cout<<"sorted array"<<endl;
    for(int i=0;i<5;i++){
        cout<<i<<":"<<arr[i]<<endl;
    }
    return 0;
}
