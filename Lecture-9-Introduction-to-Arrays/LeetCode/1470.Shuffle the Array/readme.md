# 1470. Shuffle the Array

## Problem Statement

Given an array `nums` consisting of `2n` elements in the form:

```text
[x1, x2, ..., xn, y1, y2, ..., yn]
```

Return the array in the form:

```text
[x1, y1, x2, y2, ..., xn, yn]
```

---

## Example

### Input

```cpp
nums = [2,5,1,3,4,7]
n = 3
```

### Output

```cpp
[2,3,5,4,1,7]
```

### Explanation

```text
x = [2,5,1]
y = [3,4,7]

Result:
[2,3,5,4,1,7]
```

---

## Approach

1. Create an empty vector `ans`.
2. Traverse from `0` to `n - 1`.
3. For each index:

   * Insert `nums[i]` (x element).
   * Insert `nums[i + n]` (y element).
4. Return the resulting vector.

---

## Algorithm

```text
Create an empty vector ans

For i from 0 to n-1:
    Push nums[i] into ans
    Push nums[i+n] into ans

Return ans
```

---

## C++ Solution

```cpp
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            ans.push_back(nums[i]);
            ans.push_back(nums[i + n]);
        }

        return ans;
    }
};
```

---

## Dry Run

### Input

```cpp
nums = [2,5,1,3,4,7]
n = 3
```

### Iteration 1

```cpp
ans = [2,3]
```

### Iteration 2

```cpp
ans = [2,3,5,4]
```

### Iteration 3

```cpp
ans = [2,3,5,4,1,7]
```

### Final Output

```cpp
[2,3,5,4,1,7]
```

---

## Complexity Analysis

### Time Complexity

```text
O(n)
```

The loop runs exactly `n` times.

### Space Complexity

```text
O(n)
```

An additional vector is used to store the shuffled array.

---

## Key Learning

* Splitting an array logically into two halves.
* Using `vector::push_back()`.
* Working with array indices efficiently.
* Building a new array based on a given pattern.
