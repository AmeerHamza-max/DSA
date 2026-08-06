#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int moves = 0;
        for(int i = 0; i < s.length();i++){
            if(s[i]=='('){
                open++;
            }
            else{
                if(open > 0){
                    open--;
                }
                else{
                    moves++;
                }
            }
        }
        moves+=open;
        return moves;
    }
};