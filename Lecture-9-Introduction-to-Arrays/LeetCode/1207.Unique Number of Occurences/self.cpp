#include<iostream>
using namespace std;
#include<vector>
#include<unordered_set>
#include<unordered_map>
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;

        // Frequency count
        for (int num : arr) {
            freq[num]++;
        }

        unordered_set<int> st;

        // Check frequencies are unique
        for (auto it : freq) {
            if (st.count(it.second)) {
                return false;
            }
            st.insert(it.second);
        }

        return true;
    }
};