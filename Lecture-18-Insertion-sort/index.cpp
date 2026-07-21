#include<iostream>
using namespace std;
int main(){
    int n=5;
    int arr[]={14,3,2,5,20};
    for(int i = 1; i < n ; i++){
        int temp = arr[i];
        for(int j = i -1; j >= 0; j--){
            if(arr[j] > temp){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
    }

}