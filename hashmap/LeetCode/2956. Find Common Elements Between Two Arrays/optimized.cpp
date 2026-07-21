#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {

        vector<bool> present1(101, false);
        vector<bool> present2(101, false);

        // Mark elements of nums1
        for(int num : nums1){
            present1[num] = true;
        }

        // Mark elements of nums2
        for(int num : nums2){
            present2[num] = true;
        }

        int answer1 = 0;
        int answer2 = 0;

        // Count elements of nums1 present in nums2
        for(int num : nums1){
            if(present2[num]){
                answer1++;
            }
        }

        // Count elements of nums2 present in nums1
        for(int num : nums2){
            if(present1[num]){
                answer2++;
            }
        }

        return {answer1, answer2};
    }
};