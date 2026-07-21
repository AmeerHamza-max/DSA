#include<iostream>
using namespace std;
int gcd(int a , int b){
    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }
    while(a!=b){
        if(a>b){
            a=a-b;
        }
        else{
            b-a;
        }
    }
    return a;
}
int main(){
    int a , b;
    cout<<"Enter two Numbers = ";
    cin>> a >> b;
    int g = gcd(a,b);
    cout<<g<<endl;
}