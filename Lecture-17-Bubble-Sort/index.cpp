#include<iostream>
using namespace std;
#include<vector>
int main(){
    vector<int> arr={6,2,8,4,10};
    int n=5;
    bool swapped=false;
    for(int i = 0; i < n; i++){

        for (int j = 0 ; j < n-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false){
            break;
        }
    }

    for(int i = 0 ; i < n; i++){
        cout<<arr[i]<<" ";
    }

}