# LeetCode 69 - Sqrt(x)

## Problem Statement

Given a non-negative integer `x`, return the square root of `x` rounded down to the nearest integer.

The returned integer should be the floor value of the square root.

### Examples

**Example 1**

```cpp
Input: x = 4
Output: 2
```

**Example 2**

```cpp
Input: x = 8
Output: 2
```

Explanation:

√8 = 2.828...

Since we return only the integer part, the answer is `2`.

---

## Approach

This problem can be solved efficiently using **Binary Search**.

### Key Observation

Instead of checking every number from `1` to `x`, we search in the range:

```cpp
0 to x
```

For any number `mid`:

* If `mid * mid == x`, we found the exact square root.
* If `mid * mid < x`, `mid` can be a possible answer, but there may be a larger valid value.
* If `mid * mid > x`, we need to search in the left half.

We keep storing the latest valid value in `ans`.

---

## Algorithm

1. Initialize:

   * `start = 0`
   * `end = x`
   * `ans = -1`

2. While `start <= end`:

   * Find `mid`
   * Calculate `mid * mid`
   * If equal to `x`, return `mid`
   * If less than `x`:

     * Store `mid` in `ans`
     * Search right half
   * Otherwise:

     * Search left half

3. Return `ans`

---

## Code

```cpp
class Solution {
public:
    int mySqrt(int x) {
        int s = 0;
        int e = x;
        int mid = s + (e - s) / 2;
        int ans = -1;

        while (s <= e) {
            int square = mid * mid;

            if (square == x) {
                return mid;
            }

            if (square < x) {
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }

            mid = s + (e - s) / 2;
        }

        return ans;
    }
};
```

---

## Dry Run

For:

```cpp
x = 8
```

| Start | End | Mid | Mid² | Action                |
| ----- | --- | --- | ---- | --------------------- |
| 0     | 8   | 4   | 16   | Search Left           |
| 0     | 3   | 1   | 1    | ans = 1, Search Right |
| 2     | 3   | 2   | 4    | ans = 2, Search Right |
| 3     | 3   | 3   | 9    | Search Left           |

Loop ends.

Answer:

```cpp
2
```

---

## Time Complexity

```cpp
O(log x)
```

Binary Search halves the search space in every iteration.

---

## Space Complexity

```cpp
O(1)
```

Only a few variables are used.

---

## Note

For very large values of `x`, `mid * mid` may cause integer overflow.

A safer implementation uses:

```cpp
long long square = 1LL * mid * mid;
```

This ensures correct behavior for all valid inputs.
