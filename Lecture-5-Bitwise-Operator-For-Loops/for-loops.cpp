// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cout<<"Enter the value of n = ";
//     cin>>n;

//     cout<<"Printing count from 1 to n "<<endl;
//     for(int i = 0 ; i <= n ; i++){
//         cout<<i<<endl;
//     }
//     int i = 1;

// for(; ; ){
    
//     if(i<=n){
//         cout<<i<<endl;
//         i++;
//     }
//     else{
//         break;
//     }
    
// }
// int sum = 0;
// for (int i =1 ; i <= n;i++){
//     sum = sum + i ;

// }
// cout<<sum;
// }



// Fibnocci series
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cout<<"Enter a Number = ";
//     cin>>n;
//     int t1 = 0;
//     int t2 = 1;
//     cout<<t1<<" "<<t2<<" ";
    
    
//     for(int i = 0; i < n; i++){
//         int nextNumber = t1+ t2;
//         cout<<nextNumber<<" ";
//         t1 = t2 ;
//         t2= nextNumber;
//     }
    
// }







// Prime or Not

// #include<iostream>
// using namespace std;
// int main(){
//  int n;
//  cout<<"E{nter a Number = ";
//  cin >> n;
//  for(int i = 1; i < n; i++){
//     if(n%i==0){
//         cout<<"Not a prime Number";
//         break;
//     }
//     else{
//         cout<<"Prime Number";
//         break;
//     }
//  }
// }


#include<iostream>
using namespace std;
int main(){
    // for(int i = 0 ; i < 5; i++){
    //     cout<<"Hi"<<endl;
    //     cout<<"Hey"<<endl;
    //     continue;
    //     cout<<"Reply Me Please";

    // }

    // for(int i = 0 ; i <=5; i--){
    //     cout<<i<<" ";
    //     i++;
    // }

    for(int i = 0; i <= 15; i = i+2){
        cout<< i <<" ";
        if(i&1){
            continue;
        }
        i++;
    }
}