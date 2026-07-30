# 189. Rotate Array

## Problem Statement

Given an integer array `nums`, rotate the array to the **right** by `k` steps, where `k` is non-negative.

The rotation must be performed **in-place** using **O(1)** extra space.

---

## Example 1

### Input

```text
nums = [1,2,3,4,5,6,7]
k = 3
```

### Output

```text
[5,6,7,1,2,3,4]
```

### Explanation

```text
Rotate 1 step:
[7,1,2,3,4,5,6]

Rotate 2 steps:
[6,7,1,2,3,4,5]

Rotate 3 steps:
[5,6,7,1,2,3,4]
```

---

## Example 2

### Input

```text
nums = [-1,-100,3,99]
k = 2
```

### Output

```text
[3,99,-1,-100]
```

---

# Approach (Reverse Method)

This is the most efficient solution.

Instead of moving elements one by one, we use **three reverses**.

### Step 1

If `k` is larger than the array size:

```cpp
k = k % n;
```

Example:

```text
n = 7
k = 10

10 % 7 = 3
```

Rotating 10 times is the same as rotating 3 times.

---

### Step 2

Reverse the whole array.

Before:

```text
1 2 3 4 5 6 7
```

After:

```text
7 6 5 4 3 2 1
```

---

### Step 3

Reverse the first `k` elements.

```text
7 6 5 | 4 3 2 1
```

becomes

```text
5 6 7 | 4 3 2 1
```

---

### Step 4

Reverse the remaining elements.

```text
5 6 7 | 4 3 2 1
```

becomes

```text
5 6 7 | 1 2 3 4
```

Final Answer:

```text
5 6 7 1 2 3 4
```

---

# Dry Run

### Input

```text
nums = [1,2,3,4,5,6,7]
k = 3
```

### Initial Array

```text
1 2 3 4 5 6 7
```

---

### Reverse Entire Array

```text
7 6 5 4 3 2 1
```

---

### Reverse First k Elements

```text
5 6 7 4 3 2 1
```

---

### Reverse Remaining Elements

```text
5 6 7 1 2 3 4
```

Answer:

```text
[5,6,7,1,2,3,4]
```

---

# Algorithm

1. Find the size of the array.
2. Compute:

```cpp
k = k % n;
```

3. Reverse the complete array.
4. Reverse the first `k` elements.
5. Reverse the remaining elements.
6. Return the rotated array.

---

# C++ Solution

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();
        k = k % n;

        reverse(nums.begin(), nums.end());

        reverse(nums.begin(), nums.begin() + k);

        reverse(nums.begin() + k, nums.end());
    }
};
```

---

# Why Reverse Works

Suppose

```text
nums = [1,2,3,4,5,6,7]
```

We want

```text
[5,6,7,1,2,3,4]
```

Instead of shifting every element:

First reverse everything

```text
7 6 5 4 3 2 1
```

Now the last three elements of the original array are already at the front, but in reverse order.

Reverse them:

```text
5 6 7
```

Then reverse the remaining elements:

```text
1 2 3 4
```

The desired rotation is complete.

---

# Time Complexity

Each reverse takes **O(n)** time.

Three reverses:

```text
O(n)
```

---

# Space Complexity

Only a few variables are used.

```text
O(1)
```

---

# Alternative Solutions

## 1. Extra Array

- Copy elements into another array.
- Place each element at its new position.

Time:

```text
O(n)
```

Space:

```text
O(n)
```

---

## 2. Rotate One Step at a Time

Rotate the array one position, `k` times.

Time:

```text
O(n × k)
```

Space:

```text
O(1)
```

This approach is too slow for large values of `k`.

---

## 3. Reverse Method ✅ (Best)

Time:

```text
O(n)
```

Space:

```text
O(1)
```

This is the optimal solution and the one expected in interviews.

---

# Key Takeaways

- Always compute:

```cpp
k = k % n;
```

- The reverse method performs the rotation **in-place**.
- No extra array is required.
- Uses only **constant extra space**.
- Very common interview question on arrays.

---

# LeetCode Link

https://leetcode.com/problems/rotate-array/