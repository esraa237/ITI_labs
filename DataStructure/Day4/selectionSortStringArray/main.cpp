#include <iostream>
#include<string.h>
using namespace std;
void swap(char* arr1,char* arr2){
    char temp[10];
    strcpy(temp,arr1);
    strcpy(arr1,arr2);
    strcpy(arr2,temp);
};
void Selectionsort(char arr[][10],int size){
    int min;
    for(int i=0;i<size-1;i++){
        min=i;
        for(int j=i+1;j<size;j++){
            if(strcmp(arr[j],arr[min])<0){
                min=j;
            }
        }
        if(min!=i){
            swap(arr[i],arr[min]);
        }
    }
}
int main()
{
    char arr[3][10]={"esraa","aml","nada"};
    Selectionsort(arr,3);
    for(int i=0;i<3;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}
