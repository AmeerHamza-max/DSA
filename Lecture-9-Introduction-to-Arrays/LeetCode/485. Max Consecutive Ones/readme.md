# 485. Max Consecutive Ones

## Problem Statement

Given a binary array `nums`, return the maximum number of consecutive `1`s in the array.

### Example 1

Input:
```cpp
nums = [1,1,0,1,1,1]
```

Output:
```cpp
3
```

Explanation:

- First consecutive sequence: `1,1` → length = 2
- Second consecutive sequence: `1,1,1` → length = 3
- Maximum consecutive ones = 3

---

### Example 2

Input:
```cpp
nums = [1,0,1,1,0,1]
```

Output:
```cpp
2
```

---

## Approach

We traverse the array once and maintain two variables:

- `count` → stores the current consecutive count of `1`s.
- `maxi` → stores the maximum consecutive count found so far.

### Logic

1. If the current element is `1`:
   - Increase `count`.
   - Update `maxi` using `max(maxi, count)`.

2. If the current element is `0`:
   - Reset `count` to `0` because the sequence of consecutive ones is broken.

3. Return `maxi` after traversing the entire array.

---

## Code

```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int count = 0;

        for(int i : nums) {
            if(i == 1) {
                count++;
                maxi = max(maxi, count);
            }
            else {
                count = 0;
            }
        }

        return maxi;
    }
};
```

---

## Dry Run

Input:

```cpp
nums = [1,1,0,1,1,1]
```

| Element | Count | Maxi |
|----------|--------|--------|
| 1 | 1 | 1 |
| 1 | 2 | 2 |
| 0 | 0 | 2 |
| 1 | 1 | 2 |
| 1 | 2 | 2 |
| 1 | 3 | 3 |

Final Answer:

```cpp
3
```

---

## Complexity Analysis

### Time Complexity

```cpp
O(n)
```

We traverse the array only once.

### Space Complexity

```cpp
O(1)
```

Only two extra variables are used.

---

## Key Learning

- Tracking a running count while traversing an array.
- Using a maximum variable to store the best answer found so far.
- Understanding the difference between:
  - Range-based loop (`for(int i : nums)`) → `i` is the element.
  - Index-based loop (`for(int i = 0; i < nums.size(); i++)`) → `i` is the index.

This is a classic array traversal problem and a good introduction to maintaining running counts.