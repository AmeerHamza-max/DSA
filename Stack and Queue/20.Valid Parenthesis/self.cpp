// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>
using namespace std;
int main() {
    // Write C++ code here
    cout << "Start small. Ship something.";
    string s = "()[]{}";
    vector <char> arr;
    for(int i = 0 ; i < s.length(); i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
            arr.push_back(s[i]);
        }
        else{
            if(arr.empty()){
                return false;
            }
            else if((s[i]==')' && arr.back()=='(') || (s[i]=='}' && arr.back()=='{') || (s[i]==']' && arr.back()=='[')){
                arr.pop_back();
            }
            else{
                return false;
            }
            
        }
    }
    if(arr.empty()){
        cout<<"valid";
    }
    else{
        cout<<"invalid"<<endl;
    }
    return 0;
    
}