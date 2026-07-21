#include<iostream>
using namespace std;
#include<vector>
int main(){
    int ans = 0;
    vector<int> arr={1,2,3,1};
    for(int i = 0 ; i < arr.size();i++){
        ans = ans ^ arr[i];

    }
    for(int i =1 ; i < arr.size();i++){
        ans = ans ^ i;
    }
    cout<<ans<<" ";
}