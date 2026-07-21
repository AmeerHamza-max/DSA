#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<unordered_set>
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        unordered_map<int, int> freq;

        // Count frequency of each number
        for (int num : arr) {
            freq[num]++;
        }

        unordered_set<int> seen;

        // Check if frequency is unique
        for (auto it : freq) {
            if (seen.count(it.second)) {
                return false;
            }

            seen.insert(it.second);
        }

        return true;
    }
};