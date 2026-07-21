#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<math.h>
#include<climits>
#include<algorithm>
class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> freq;

        // Count frequency of each character
        for (char ch : s) {
            freq[ch]++;
        }

        vector<pair<char, int>> arr;

        // Store character and frequency
        for (auto it : freq) {
            arr.push_back({it.first, it.second});
        }

        // Sort by frequency (descending)
        sort(arr.begin(), arr.end(),
             [](pair<char, int>& a, pair<char, int>& b) {
                 return a.second > b.second;
             });

        string ans = "";

        // Build answer
        for (auto it : arr) {
            ans.append(it.second, it.first);
        }

        return ans;
    }
};