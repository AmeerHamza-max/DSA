#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> result;
        int i = 0;
        int j = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();

        // Two Pointers merge logic
        while (i < n1 && j < n2) {
            int id1 = nums1[i][0];
            int id2 = nums2[j][0];
            int val1 = nums1[i][1];
            int val2 = nums2[j][1];

            if (id1 == id2) {
                result.push_back({id1, val1 + val2});
                i++;
                j++;
            } 
            else if (id1 < id2) {
                result.push_back({id1, val1});
                i++;
            } 
            else {
                result.push_back({id2, val2});
                j++;
            }
        }

        // Push remaining elements from nums1
        while (i < n1) {
            result.push_back(nums1[i]);
            i++;
        }

        // Push remaining elements from nums2
        while (j < n2) {
            result.push_back(nums2[j]);
            j++;
        }

        return result;
    }
};

// Helper function to print 2D vector
void print2DVector(const vector<vector<int>>& vec) {
    cout << "[";
    for (size_t k = 0; k < vec.size(); ++k) {
        cout << "[" << vec[k][0] << "," << vec[k][1] << "]";
        if (k != vec.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Test Case 1
    vector<vector<int>> nums1 = {{1, 2}, {2, 3}, {4, 5}};
    vector<vector<int>> nums2 = {{1, 4}, {3, 2}, {4, 1}};

    cout << "--- Test Case 1 ---" << endl;
    cout << "Input nums1: ";
    print2DVector(nums1);
    cout << "Input nums2: ";
    print2DVector(nums2);

    vector<vector<int>> output1 = sol.mergeArrays(nums1, nums2);
    cout << "Merged Output: ";
    print2DVector(output1);

    cout << endl;

    // Test Case 2
    vector<vector<int>> nums3 = {{2, 4}, {3, 6}, {5, 5}};
    vector<vector<int>> nums4 = {{1, 3}, {4, 3}};

    cout << "--- Test Case 2 ---" << endl;
    cout << "Input nums1: ";
    print2DVector(nums3);
    cout << "Input nums2: ";
    print2DVector(nums4);

    vector<vector<int>> output2 = sol.mergeArrays(nums3, nums4);
    cout << "Merged Output: ";
    print2DVector(output2);

    return 0;
}