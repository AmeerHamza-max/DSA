#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans;
        for(int i = 0; i < n; i++){
            ans.push_back(nums[i]);
        }
        ans.insert(ans.end(),ans.begin(),ans.end());
        return ans;
        
    }
};