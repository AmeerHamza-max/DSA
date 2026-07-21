#include<iostream>
using namespace std;
#include<stack>
int main(){
    stack<string> s1;
    s1.push("Ameer");
    s1.push("Hamza");
    s1.push("Rana");
    cout<<"Top Element = "<<s1.top()<<endl;
    s1.pop();
    cout<<"Top Element = "<<s1.top()<<endl;
    cout<<"Size of stack = "<<s1.size()<<endl;
    cout<<"Empty or Not = "<<s1.empty()<<endl;
}