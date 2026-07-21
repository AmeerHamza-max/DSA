#include<iostream>
using namespace std;
#include<set>
int main(){
 set<int> s;
 s.insert(5);
 s.insert(5);
 s.insert(5);
 s.insert(5);
 s.insert(5);
 s.insert(5);
 
 s.insert(4);
 s.insert(4);
 s.insert(4);
 s.insert(4);
 s.insert(4);
 s.insert(4);
 s.insert(3);
 s.insert(2);
 s.insert(1);
 s.insert(1);
 s.insert(1);
 s.insert(1);
 for(int i:s){
    cout<<i<<endl;
 }
 s.erase(s.begin());
for(int i:s){
    cout<<i<<endl;
 }

 for(auto i:s){
   cout<<i<<endl;
 }
 cout<<endl;
 cout<<"-5 is present or not -> "<<s.count(-5)<<endl;


set<int>::iterator itr=s.find(5);
cout<<"Value Present at ITR  "<<*itr<<endl;


}