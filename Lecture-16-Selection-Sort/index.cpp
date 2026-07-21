#include<iostream>
using namespace std;
#include<climits>
int main(){
    
    int arr[6]={20,15,25,21,24,9};

    for(int i = 0 ; i < 5 ; i++){
        int min=i;
        for(int j = i+1 ; j < 6 ; j++){
            if(arr[j] < arr[min]){
                min=j;
            }

        }
        swap(arr[min],arr[i]);
        
    }
    for(int i = 0 ; i < 6;i++){
        cout<<arr[i]<<" ";
    }
}