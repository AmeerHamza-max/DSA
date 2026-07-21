#include<iostream>
using namespace std;
#include<queue>
int main(){
    priority_queue<int> maxi;
    priority_queue<int,vector<int>,greater<int>> mini;
    maxi.push(1);
    maxi.push(2);
    maxi.push(3);
    for(int i = 0 ; i < maxi.size(); i++){
        cout<<maxi.top()<<" ";
        maxi.pop();
    }
    cout<<endl;

}