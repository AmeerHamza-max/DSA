#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
        vector<char> ch;
        for(int i = 0 ; i < s.length(); i++){
            if(ch.empty()){
                ch.push_back(s[i]);
            }
            else if(ch.back()==s[i]){
                ch.pop_back();
            }
            else{
                ch.push_back(s[i]);
            }
        }
        string str(ch.begin(),ch.end());
        return str;

    }
};