#include<iostream>
using namespace std;
void printArray(int arr[],int n ){
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}
void swapAlternate(int arr[],int size){
    for(int i = 0 ; i < size; i+=2){
        if(i+1 < size ){
            swap(arr[i],arr[i+1]);
        }
    }
}
int main(){
    int even[6]={1,3,2,7,11,8};
    int odd[5]={11,33,9,76,43};
    int size = sizeof(even)/sizeof(int);
    int size1 = sizeof(odd)/sizeof(int);
    printArray(even,size);
    swapAlternate(even,size);
    printArray(even,size);
    printArray(odd,size1);
    swapAlternate(odd,size1);
    printArray(odd,size1);
    
}