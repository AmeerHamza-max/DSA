#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;

        // Elements smaller than pivot
        for (int num : nums) {
            if (num < pivot)
                ans.push_back(num);
        }

        // Elements equal to pivot
        for (int num : nums) {
            if (num == pivot)
                ans.push_back(num);
        }

        
        for (int num : nums) {
            if (num > pivot)
                ans.push_back(num);
        }

        return ans;
    }
};