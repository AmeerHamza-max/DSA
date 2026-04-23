#include<iostream>
using namespace std;
int main(){
   int n;
   cin >> n;
   cout<<"Value of n is :"<<n<<endl;
   if (n > 0){
    cout<<"N is Positive"<<endl;
   }
   else{
    cout<<"N is Negative"<<endl;
   }
   int a,b;

   cout<<"Enter the value of A = ";
   a= cin.get();//to get the value of space enter and tab
   cin >> a;
   cout<<"Enter the value of B = ";
   cin  >> b;
   cout<<"Value of a and b is "<<a <<" "<<b<<endl;

   if(a > b){
      cout<<"A is greater"<<endl;
   }
   if(b>a){
      cout<<"B is greater"<<endl;
   }


   int a1;
   cout<<"Enter the value of A = ";
   cin>>a1;
   if(a>0){
      cout<<"A is positive";

   }
   else{
      if(a<0){
         cout<<"A is negative";
      }
      else{
         cout<<"A is 0";
      }
   }

   int a2;
   cout<<"Enter the value of a2 = ";
   cin>>a2;
   if(a2>0){
      cout<<"a2 is positive";
   }
   else if(a2<0){
      cout<<"a2 is negative";
   }
   else{
      cout<<"a2 is 0";
   }

   int age;
   cout<<"Enter your age = ";
   cin >> age;
   return 0;
}