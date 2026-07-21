#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> freq;
        
        for(int num : nums){
            freq[num]++;
        }

        int count = 0;
        for(auto it : freq){
            int f = it.second;
            count += (f * (f - 1)) / 2;
        }

        return count;
    }
};