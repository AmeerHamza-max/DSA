#include<iostream>
using namespace std;
#include<climits>
int main(){
    int arr[4]={1,2,3,4};
    int arr1[4]={3,4};
    int arr2[5];
    int size1=sizeof(arr)/sizeof(int);
    int size=sizeof(arr)/sizeof(int);
    for(int i = 0 ; i < size;i++){
        for(int j=0;j < size1;j++){
            if(arr[i]<arr[j]){
                break;
            }
            if(arr[i]==arr1[j]){
                arr2[i]=arr[i];
                arr1[j]=INT_MIN;
                break;
            }
        }
    }
    int size2=sizeof(arr2)/sizeof(int);
    for(int i = 0 ; i < size2; i++){
        cout<<arr2[i]<<" ";
    }
}