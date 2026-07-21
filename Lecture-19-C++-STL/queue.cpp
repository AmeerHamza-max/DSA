#include<iostream>
using namespace std;
#include<queue>
int main(){
    queue<string> q;
    q.push("Ameer");
    q.push("Hamza");
    q.push("Rana");
    cout<<"Size before Pop = "<<q.size()<<endl;
    cout<<"First Element = "<<q.front()<<endl;
    q.pop();
    cout<<"First Element = "<<q.front()<<endl;
    cout<<"Size after Pop = "<<q.size()<<endl;



}