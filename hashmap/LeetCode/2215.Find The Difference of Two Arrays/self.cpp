#include<iostream>
#include<vector>
using namespace std;
#include<unordered_set>
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        vector<int> ans1, ans2;

        for (int x : set1) {
            if (set2.count(x) == 0) {
                ans1.push_back(x);
            }
        }

        for (int x : set2) {
            if (set1.count(x) == 0) {
                ans2.push_back(x);
            }
        }

        return {ans1, ans2};
    }
};