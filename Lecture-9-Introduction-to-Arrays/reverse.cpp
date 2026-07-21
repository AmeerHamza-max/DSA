#include<iostream>
using namespace std;
#include<utility>
void reverse(int arr[],int size){
    int start = 0;
    int end = size-1;
    while(start <= end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}
void printArray(int arr[],int n ){
    for(int i = 0 ; i < n; i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[4]={2,7,5,9};
    int size = sizeof(arr)/sizeof(int);
    int arr1[5]={2,6,3,9,4};
    int size1=sizeof(arr)/sizeof(int);
    printArray(arr,size);
    cout<<endl;
    printArray(arr1,size1);
    cout<<endl;
    reverse(arr,size);
    reverse(arr1,size1);
    printArray(arr,size);
    cout<<endl;
    printArray(arr1,size1);
    
    
}