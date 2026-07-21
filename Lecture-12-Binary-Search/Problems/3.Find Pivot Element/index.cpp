#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:

    int getPivot(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] >= nums[0]) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        return s;
    }

    int binarySearch(vector<int>& nums, int s, int e, int target) {

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target)
                return mid;

            if (nums[mid] < target)
                s = mid + 1;
            else
                e = mid - 1;
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {

        int n = nums.size();

        // Special case: array not rotated
        if (nums[0] <= nums[n - 1]) {
            return binarySearch(nums, 0, n - 1, target);
        }

        int pivot = getPivot(nums);

        if (target >= nums[pivot] && target <= nums[n - 1]) {
            return binarySearch(nums, pivot, n - 1, target);
        } else {
            return binarySearch(nums, 0, pivot - 1, target);
        }
    }
};