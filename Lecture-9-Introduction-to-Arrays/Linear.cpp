#include<iostream>
using namespace std;
bool linearSearch(int arr[],int size,int target){
    for(int i = 0 ; i < size; i++ ){
        if(arr[i]==target){
            return 1;
        }

    }
    return 0;
}
int main(){
    int arr[10]={5,7,-2,10,-2,0,5,22,2};
    int size = sizeof(arr)/sizeof(int);
    int target=1;
    // whether 1 is present in it or not
    int ans=linearSearch(arr,size,target);
    if(ans){
        cout<<"target Found"<<endl;
    }
    else{
        cout<<"Target not found"<<endl;
    }
    return 0;

}