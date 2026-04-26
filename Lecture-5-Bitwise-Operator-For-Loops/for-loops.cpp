#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the value of n = ";
    cin>>n;

    cout<<"Printing count from 1 to n "<<endl;
    for(int i = 0 ; i <= n ; i++){
        cout<<i<<endl;
    }
    int i = 1;

for(; ; ){
    
    if(i<=n){
        cout<<i<<endl;
        i++;
    }
    else{
        break;
    }
    
}
int sum = 0;
for (int i =1 ; i <= n;i++){
    sum = sum + i ;

}
cout<<sum;
}