// Manual way
// #include<iostream>
// using namespace std;
// int main(){
//     int a , b;
//     cin >> a >> b;
//     int ans = 1;
//     for(int i = 1; i <=b ; i++){
//         ans = ans * a;
//     }
//     cout<<"Answer is "<<ans<<endl;

//     int c , d;
//     cin >> c >> d;
//     int ans1 = 1;
//     for(int i = 1; i <=b ; i++){
//         ans1 = ans1 * c;
//     }
//     cout<<"Answer is "<<ans1<<endl;
//     return  0;
// }


// With Parameters

// #include<iostream>
// using namespace std;

// int power(int a , int b){
//     int ans = 1;
//     for(int i =1 ; i <=b; i++){
//         ans = ans * a;
//     }
//     return ans;
// }

// int  main (){
//     int a , b;
//     cin >> a >> b;
//     int ans1 = power(a,b);
//     cout<<"This is the Power of A = "<<ans1<<endl;
//     cin >> a >> b;
//     int ans2 = power(a,b);
//     cout<<"This is the Power of A = "<<ans2<<endl;
//     cin >> a >> b;
//     int ans3 = power(a,b);
//     cout<<"This is the Power of A = "<<ans3<<endl;
//     cin >> a >> b;
//     int ans4 = power(a,b);
//     cout<<"This is the Power of A = "<<ans4<<endl;
// }




/// WIthout parameters


// #include<iostream>
// using namespace std;

// int power(){
//     int a , b;
//     cin >> a >> b;
//     int ans = 1;
//     for(int i =1 ; i <=b; i++){
//         ans = ans * a;
//     }
//     return ans;
// }

// int  main (){
    
//     int ans1 = power();
//     cout<<"This is the Power of A = "<<ans1<<endl;
//     int ans2 = power();
//     cout<<"This is the Power of A = "<<ans2<<endl;
//     int ans3 = power();
//     cout<<"This is the Power of A = "<<ans3<<endl;
//     int ans4 = power();
//     cout<<"This is the Power of A = "<<ans4<<endl;
// }




// Direct cout the function 
// #include <iostream>
// using namespace std;
// int power(){
//     int a , b;
//     cin >> a >> b;
//     int ans = 1;
//     for(int i =1 ; i <=b; i++){
//         ans = ans * a;
//     }
//     return ans;
// }

// int  main (){
    
    
//     cout<<"This is the Power of A = "<<power()<<endl;
//     cout<<"This is the Power of A = "<<power()<<endl;
//     cout<<"This is the Power of A = "<<power()<<endl;
//     cout<<"This is the Power of A = "<<power()<<endl;
// }


// #include<iostream>
// using namespace std;

// bool isEven(int a){
//     //odd
//     if(a&1){
//         return 0;
//     }
//     else{
//         return 1;
//     }
// }
// int main(){
//     int num;
//     cin >> num;
//     if(isEven(num)){
//         cout<<"Number is even ";
//     }
//     else{
//         cout<<"Number is Odd";
//     }
//     return 0;
// }


// NCR Factorial 
// #include<iostream>
// using namespace std;
// int factorial(int n){
//     int ans = 1;
//     for(int i=1;i<=n;i++){
//         ans=ans*i;
//     }
//     return ans;
// }
// int nCr(int n, int r){
//     int num=factorial(n);
//     int denom=factorial(r)*factorial(n-r);
//     int ans = num/denom;
//     return ans;
// }
// int main(){
//     int n , r;
//     cin >> n >> r;
//     int ans=nCr(n,r);
//     cout<<"Answer of nCr is = "<<ans<<endl;
// }

// #include<iostream>
// using namespace std;
// void printCounting(int n){
//     for(int i= 1; i <=n; i++){
//         cout<<"Number = "<<i<<endl;
//     }
//      return;
// }
// int main(){
//     int n; 
//     cin >> n;
//     printCounting(n);
// }


//Prime no or not

// #include<iostream>
// using namespace std;
// bool isPrime(int n){
//     for(int i = 2; i < n; i++){
//         if(n%i==0){
//             return 0;
//         }
//         else{
//             return 1;
//         }
//     }
// }
// int main(){
//     int n;
//     cin >> n;
//     if(isPrime(n)){
//         cout<<"Prime Number"<<endl;
//     }
//     else{
//         cout<<"Not a Prime No"<<endl;
//     }
// }


// A.P = (3*n + 7)
// #include<iostream>
// using namespace std;
// void AP(int n ){
//     cout<<"AP is = "<<3*n+7<<endl;
// }
// int main(){
//     int n;
//     cin >> n;
//     AP(n);
// }



// #include <iostream>
// using namespace std;
// void setBits(){
//     for(int i = 4; i <= 6; i++) {

//         int count = 0;
//         int num = i;

//         while(num > 0) {

//             if(num % 2 == 1) {  // agar remainder 1 aya
//                 count++;
//             }

//             num = num / 2;
//         }

//         cout << "Set bits in " << i << " = " << count << endl;
//     }
// }


// int main() {
    
// }



// Fibonacci number
// #include<iostream>
// using namespace std;
// void fibonacci(int n){
//     int t1=0,t2=1;
//     cout<<t1<<" "<<t2<<" ";
//     int next =0;
//     for(int i=t1;i<=n;i=t1+t2){
//         next=t1+t2;
//         cout<<next<<" ";
//         t1=t2;
//         t2=next;

//     }

// }
// int main(){
//     int n;
//     cin >> n;
//     fibonacci(n);

// }


#include<iostream>
using namespace std;
void dummy(int n ){
    n++;
    cout<<"n is "<<n<<endl;
}
int main (){
    int n ;
    cin >> n;
    dummy(n);
    cout<<"Number n is "<<n<<endl;
}