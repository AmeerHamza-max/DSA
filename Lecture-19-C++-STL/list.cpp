#include<iostream>
using namespace std;
#include<list>
int main(){
    list<int> l;
    l.push_back(1);
    l.push_front(2);
    // list<int> n(l);
    list <int> n(5,100);
    for(int i:l){
        cout<<i<<" ";
    }
    cout<<endl;
    l.erase(l.begin());
    cout<<"After erase "<<endl;
    for(int i:l){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Size of list = "<<l.size()<<endl;
    for(int i:n){
        cout<<i<<" ";
    }
    cout<<endl;


}