#include<iostream>
using namespace std;
int main(){
    int arr[5]={1,3,4,1,3};
    int ans = 0 ; 
    int size=sizeof(arr)/sizeof(int);
    for(int i = 0 ; i < size ; i ++){
        ans = ans ^ arr[i];
    }
    cout<<ans<<endl;
    return 0;
    
}