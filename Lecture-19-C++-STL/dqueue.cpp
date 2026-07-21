#include<iostream>
using namespace std;
#include<deque>
int main(){
    deque<int> d;
    d.push_back(1);
    d.push_front(2);
    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"After Pop Back"<<endl;
    // d.pop_back();
    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"After Pop Front"<<endl;
    // d.pop_front();
    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Print First Index Element -> "<<d.at(1)<<endl;

    cout<<"front = "<<d.front()<<endl;
    cout<<"Back = "<<d.back()<<endl;

    cout<<"Empty or Not = "<<d.empty()<<endl;
    
    cout<<"Before erase = "<<d.size()<<endl;

    d.erase(d.begin(),d.begin()+1);
    cout<<"After erase = "<<d.size()<<endl;


}