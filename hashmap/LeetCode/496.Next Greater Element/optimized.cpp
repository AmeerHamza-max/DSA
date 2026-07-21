#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans;

        for (int i = 0; i < nums1.size(); i++) {

            int nextGreater = -1;

            // Find nums1[i] in nums2
            for (int j = 0; j < nums2.size(); j++) {

                if (nums1[i] == nums2[j]) {

                    // Search on the right side
                    for (int k = j + 1; k < nums2.size(); k++) {

                        if (nums2[k] > nums2[j]) {
                            nextGreater = nums2[k];
                            break;
                        }
                    }

                    break;
                }
            }

            ans.push_back(nextGreater);
        }

        return ans;
    }
};