#include<iostream>
using namespace std;
int main(){
    int arr[]={12,54,23,9,4,15};
    int n = 6;
    for(int i = 1; i < n; i++){
        int temp = arr[i];
        int j = i-1;
        for(; j >= 0 ; j--){
            if(arr[j] > temp){
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
            
        }
        arr[j+1]=temp;
        
    }
    for(int i = 0 ; i < n; i++){
        cout<<arr[i]<<" ";
    }
}