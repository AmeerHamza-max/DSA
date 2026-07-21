#include<iostream>
using namespace std;
int sqrt(int x){
    int s=0;
    int e = x;
    long long int mid=s+(e-s)/2;
    long long int ans=-1;
    while(s <= e){
        int square=mid * mid;
        if(square == x){
            return mid;
        }
        else if(square<x){
            ans =mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
int main(){
    cout<<"The answer is = "<<sqrt(36)<<endl;
    return 0;

}