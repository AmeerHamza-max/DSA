#include<iostream>
using namespace std;
#include<vector>
int main(){
    int count = 0;
    int n;
    cout<<"Enter a Number = ";
    cin >> n;
    vector <bool> prime(n,true);
    prime[0]=false;
    prime[1]=false;
    for(int i = 2 ; i*i<n;i++){
        if(prime[i]){
        for(int j = i*i;j<n;j+=i){
            prime[j]=false;
        }
        }

    }
    for(int i = 2;  i < n ; i++){
        if(prime[i]){
            count++;
        }
    }
    cout<<count<<endl;
    
}