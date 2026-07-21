# Search in Rotated Sorted Array

## Problem Statement

Given a sorted array that has been rotated at an unknown pivot index, find the index of a target element in **O(log n)** time complexity.

### Example

```cpp
Input:
nums = [4,5,6,7,0,1,2]
target = 0

Output:
4
```

The original sorted array was:

```cpp
[0,1,2,4,5,6,7]
```

After rotation:

```cpp
[4,5,6,7,0,1,2]
```

---

# Approach

The solution is divided into two parts:

1. Find the Pivot Index
2. Perform Binary Search in the Correct Half

---

## Step 1: Find the Pivot

The pivot is the index of the smallest element in the rotated array.

Example:

```cpp
[4,5,6,7,0,1,2]
```

Here:

```cpp
Pivot Index = 4
Pivot Value = 0
```

### Logic

* If `nums[mid] >= nums[0]`, then we are on the left sorted part.
* Move to the right side.
* Otherwise, move to the left side.
* Continue until `start == end`.

### Pivot Function

```cpp
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
```

### Dry Run

```cpp
nums = [4,5,6,7,0,1,2]
```

| Start | End | Mid | Value | Action      |
| ----- | --- | --- | ----- | ----------- |
| 0     | 6   | 3   | 7     | Move Right  |
| 4     | 6   | 5   | 1     | Move Left   |
| 4     | 5   | 4   | 0     | Pivot Found |

Result:

```cpp
Pivot = 4
```

---

## Step 2: Binary Search

After finding the pivot, the array is divided into two sorted parts:

```cpp
[4,5,6,7] [0,1,2]
```

Now determine where the target lies.

### Case 1

If:

```cpp
target >= nums[pivot]
&&
target <= nums[n-1]
```

Search in the right half.

### Case 2

Otherwise search in the left half.

---

## Binary Search Function

```cpp
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
```

---

# Complete Solution

```cpp
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

        if (nums[0] <= nums[n - 1]) {
            return binarySearch(nums, 0, n - 1, target);
        }

        int pivot = getPivot(nums);

        if (target >= nums[pivot] &&
            target <= nums[n - 1]) {

            return binarySearch(nums,
                                pivot,
                                n - 1,
                                target);
        }

        return binarySearch(nums,
                            0,
                            pivot - 1,
                            target);
    }
};
```

---

# Example Walkthrough

### Input

```cpp
nums = [4,5,6,7,0,1,2]
target = 0
```

### Step 1

Find Pivot:

```cpp
pivot = 4
```

### Step 2

Check target range:

```cpp
0 >= nums[4]
0 <= nums[6]
```

True

Perform binary search on:

```cpp
[0,1,2]
```

Target found at:

```cpp
Index = 4
```

### Output

```cpp
4
```

---

# Time Complexity

### Finding Pivot

```cpp
O(log n)
```

### Binary Search

```cpp
O(log n)
```

### Total

```cpp
O(log n)
```

---

# Space Complexity

```cpp
O(1)
```

No extra data structure is used.

---

# Key Learning Points

* Rotated sorted arrays can still be solved using Binary Search.
* First identify the pivot (smallest element).
* Divide the array into two sorted halves.
* Apply Binary Search on the appropriate half.
* Overall complexity remains O(log n).

This problem is one of the most important Binary Search interview questions and builds the foundation for many advanced search problems.
