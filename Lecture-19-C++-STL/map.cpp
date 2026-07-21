#include<iostream>
using namespace std;
#include<map>
int main(){
    map<int,string> m;
    m[1]="Ameer";
    m[12]="JJ";
    m[2]="Hamza";
    // for(auto i:m){
    //     cout<<i.first<<endl;
    // }
    cout<<"before erase"<<endl;
    m.insert({5,"bheem"});
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    cout<<"Finding 13 -> "<<m.count(13)<<endl;
    m.erase(12);
    cout<<"After Erase "<<endl;
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    auto it = m.find(5);
    for(auto i=it; i!=m.end();i++){
        cout<<(*i).first<<endl;
    }
}