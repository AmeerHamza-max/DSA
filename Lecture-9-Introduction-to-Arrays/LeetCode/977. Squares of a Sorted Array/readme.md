# 977. Squares of a Sorted Array

## Problem

Given a sorted integer array `nums`, return an array of the squares of each number sorted in non-decreasing order.

### Example

```cpp
nums = {-4, -1, 0, 3, 10}
```

Output:

```cpp
{0, 1, 9, 16, 100}
```

---

# My First Approach

I tried to:

1. Square every element.
2. Store squares in another vector.
3. Find the minimum value.
4. Push the minimum value into the result vector.

### Issues I Faced

#### Issue 1: Infinite Loop

I wrote:

```cpp
for(int j = 0; j < nums.size(); j++){
    nums.push_back(nums[j] * nums[j]);
}
```

Problem:

* `push_back()` increases the size of the vector.
* `nums.size()` keeps increasing.
* The loop never ends.

**Lesson:** Never modify a vector's size while iterating using its current size as the loop condition.

---

#### Issue 2: Wrong Minimum Initialization

I wrote:

```cpp
int min = INT_MIN;
```

Problem:

* `INT_MIN` is already the smallest possible integer.
* Condition:

```cpp
if(min > second[i])
```

never becomes true.

**Lesson:** To find a minimum value, start with the first element or use `INT_MAX`.

---

#### Issue 3: Using push_back Instead of Sorting

I wrote:

```cpp
second.push_back(min);
```

Problem:

* This adds duplicate values.
* It does not sort the array.

**Lesson:** Sorting requires swapping positions, not adding elements.

---

# Better Approach (Selection Sort)

### Idea

1. Store all squares in a new vector.
2. Find the minimum element.
3. Swap it with the current position.
4. Repeat for all positions.

### Complexity

* Time Complexity: O(n²)
* Space Complexity: O(n)

This works but is not optimal.

---

# Optimal Approach (Two Pointers)

### Observation

The original array is already sorted.

Example:

```cpp
{-4, -1, 0, 3, 10}
```

Squares become:

```cpp
{16, 1, 0, 9, 100}
```

The largest square is always at either:

* Left end
* Right end

### Strategy

Use:

```cpp
left = 0
right = n - 1
```

Compare:

```cpp
nums[left] * nums[left]
nums[right] * nums[right]
```

Place the larger square at the end of the answer array.

Move the corresponding pointer.

---

# Dry Run

Input:

```cpp
{-4, -1, 0, 3, 10}
```

Comparisons:

```text
16 vs 100 -> 100
16 vs 9   -> 16
1 vs 9    -> 9
1 vs 0    -> 1
0         -> 0
```

Result:

```cpp
{0, 1, 9, 16, 100}
```

---

# Final Solution

```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);

        int left = 0;
        int right = n - 1;
        int index = n - 1;

        while (left <= right) {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];

            if (leftSquare > rightSquare) {
                ans[index] = leftSquare;
                left++;
            } else {
                ans[index] = rightSquare;
                right--;
            }

            index--;
        }

        return ans;
    }
};
```

---

# Revision Notes

✅ Array is already sorted.

✅ Largest square is always at either end.

✅ Use Two Pointers (`left`, `right`).

✅ Fill answer array from back to front.

✅ Time Complexity = O(n).

✅ Space Complexity = O(n).

✅ Expected LeetCode solution.

---

# Key Takeaway

Whenever an array is sorted and you need to compare extreme values, think about the **Two Pointers** technique before using sorting.
