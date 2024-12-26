#include <iostream>

using namespace std;
int binarySearch(int* arr,int target,int size){
//Sort procsess
int low=0;
int high=size-1;
int mid;
while(low<=high){
    mid=(high+low)/2;
    if(arr[mid]==target)return mid;
    else if(arr[mid]<target)low=mid+1;
    else high=mid-1;
}
return -1;
}
int binarySearchRec(int low,int high,int* arr,int target){
    //Sort procsess
    if(low>high)return -1;
    mid=(high+low)/2;
    if(arr[mid]==target)return mid;
    else if(arr[mid]<target)binarySearchRec(mid+1,high,arr,target);
    else binarySearchRec(low,mid-1,arr,target);
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
