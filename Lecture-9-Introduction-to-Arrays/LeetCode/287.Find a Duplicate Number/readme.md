# Find the Duplicate Number

## Problem Statement

Given an array `nums` containing `n + 1` integers where each integer is in the range `[1, n]`, return the duplicate number.

## Approach: Sorting

### Idea

The main idea is to sort the array first. After sorting, any duplicate numbers will appear next to each other.

We then traverse the sorted array and compare each element with its previous element. If two adjacent elements are equal, that value is the duplicate number.

### Steps

1. Sort the array in ascending order.
2. Iterate through the array starting from index `1`.
3. Compare the current element with the previous element.
4. If both elements are equal, return that value as the duplicate number.
5. If no duplicate is found, return `-1`.

### Code

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1]) {
                return nums[i];
            }
        }

        return -1;
    }
};
```

### Example

Input:

```cpp
nums = [1,3,4,2,2]
```

After Sorting:

```cpp
[1,2,2,3,4]
```

Comparison:

```cpp
2 == 2
```

Duplicate Number:

```cpp
2
```

### Time Complexity

* Sorting: `O(n log n)`
* Traversal: `O(n)`
* Overall: `O(n log n)`

### Space Complexity

* `O(1)` (excluding the space used by the sorting algorithm)

## Key Learning

Sorting is a simple and intuitive way to identify duplicate elements because duplicates become adjacent after sorting.
