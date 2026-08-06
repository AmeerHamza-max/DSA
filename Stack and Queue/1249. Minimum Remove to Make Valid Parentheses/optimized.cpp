#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minRemoveToMakeValid(string s) {

        stack<int> st;

        // First pass
        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {
                st.push(i);
            }
            else if (s[i] == ')') {

                if (!st.empty()) {
                    st.pop();
                }
                else {
                    s[i] = '*';
                }
            }
        }

        // Remove extra '('
        while (!st.empty()) {
            s[st.top()] = '*';
            st.pop();
        }

        // Build answer
        string ans = "";

        for (char ch : s) {
            if (ch != '*') {
                ans += ch;
            }
        }

        return ans;
    }
};