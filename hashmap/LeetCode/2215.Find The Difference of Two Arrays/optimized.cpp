#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans1, ans2;

        // Elements in nums1 but not in nums2
        for (int i = 0; i < nums1.size(); i++) {

            bool found = false;

            // Check if nums1[i] exists in nums2
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    found = true;
                    break;
                }
            }

            // If not found, check for duplicates in ans1
            if (!found) {
                bool alreadyPresent = false;

                for (int k = 0; k < ans1.size(); k++) {
                    if (ans1[k] == nums1[i]) {
                        alreadyPresent = true;
                        break;
                    }
                }

                if (!alreadyPresent) {
                    ans1.push_back(nums1[i]);
                }
            }
        }

        // Elements in nums2 but not in nums1
        for (int i = 0; i < nums2.size(); i++) {

            bool found = false;

            // Check if nums2[i] exists in nums1
            for (int j = 0; j < nums1.size(); j++) {
                if (nums2[i] == nums1[j]) {
                    found = true;
                    break;
                }
            }

            // If not found, check for duplicates in ans2
            if (!found) {
                bool alreadyPresent = false;

                for (int k = 0; k < ans2.size(); k++) {
                    if (ans2[k] == nums2[i]) {
                        alreadyPresent = true;
                        break;
                    }
                }

                if (!alreadyPresent) {
                    ans2.push_back(nums2[i]);
                }
            }
        }

        return {ans1, ans2};
    }
};