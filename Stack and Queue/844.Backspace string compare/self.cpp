#include<bits/stdc++.h>
// #include<vector>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> arr1;
        vector<char> arr2;

        // Process string s
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '#') {
                arr1.push_back(s[i]);
            } else {
                if (!arr1.empty()) {
                    arr1.pop_back();
                }
            }
        }

        // Process string t
        for (int i = 0; i < t.length(); i++) {
            if (t[i] != '#') {
                arr2.push_back(t[i]);
            } else {
                if (!arr2.empty()) {
                    arr2.pop_back();
                }
            }
        }

        return arr1 == arr2;
    }
};