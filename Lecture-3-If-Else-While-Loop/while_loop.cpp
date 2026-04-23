// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     int i = 1;
//     int sum =0;
//     // while (i <= n)
//     // {
//     //     cout<<i<<" ";
//     //     i = i + 1;
//     // }
//     while( i<=n){
//         sum = sum + i;
//         i=i+1;

//     }
//     cout<<sum<<" ";    
// }

// #include<iostream>
// using namespace std; 
// int main (){
//     int n;
//     cout<<"Enter a Number : ";
//     cin >> n;
//     int i = 1 ;
//     while(i<=n){
//         if(i%2==0){
//             cout<<i<<" even number"<<endl;
//         }
//         else{
//             cout<<i<<"odd number"<<endl;
//         }
//         i = i + 1;
//     }
// }


// Farenheit to celcius table






// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cout<<"Enter a number = ";
//     cin >> n;
//     int i = 2;
//     while( i < n){
//         if(n%i==0){
//             cout<<" Not Prime Number"<<endl;
//             break;

//         }
//         else{
//             cout<<" Prime Number"<<endl;
            
//         }
//         i = i+ 1;
//     }
    
// }


#include<iostream>
using namespace std;
int main (){
    int n ;
    cin >> n;
    int i = 1;

    while(i <= n){
        int j = 1;
        while (j <= n){
        cout<<"*"<<" ";
        j=j+1;
        }
        i=i+1;
        cout<<endl;

    }
    
}