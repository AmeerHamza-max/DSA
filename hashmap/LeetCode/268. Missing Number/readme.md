# 268. Missing Number

## Problem

Given an array `nums` containing `n` distinct numbers in the range `[0, n]`.

Return the only number that is missing.

---

## Example

### Example 1

Input:

nums = [3,0,1]

Output:

2

Explanation

Numbers should be

0 1 2 3

But 2 is missing.

---

### Example 2

Input

nums = [0,1]

Output

2

---

### Example 3

Input

nums = [9,6,4,2,3,5,7,0,1]

Output

8

---

# Approach (Sum Formula)

If every number from **0 to n** were present, then their total sum would be

Expected Sum

```
n × (n + 1) / 2
```

Now calculate the sum of all elements in the array.

Missing Number

```
Expected Sum - Actual Sum
```

---

## Dry Run

Input

```
nums = [3,0,1]
```

### Step 1

```
n = 3
```

### Step 2

Expected Sum

```
3 × 4 / 2 = 6
```

### Step 3

Actual Sum

```
3 + 0 + 1 = 4
```

### Step 4

Missing Number

```
6 - 4 = 2
```

Answer = **2**

---

## Algorithm

1. Find `n = nums.size()`.
2. Compute expected sum.

```
n*(n+1)/2
```

3. Find the actual sum of the array.
4. Return

```
expectedSum - actualSum
```

---

## Code

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();

        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;

        for (int num : nums)
            actualSum += num;

        return expectedSum - actualSum;
    }
};
```

---

# Complexity

Time Complexity

```
O(n)
```

Space Complexity

```
O(1)
```

---

# Follow Up (XOR Method)

Another O(n) and O(1) solution uses XOR.

Properties:

```
a ^ a = 0
a ^ 0 = a
```

If we XOR all indices and all array elements together, every existing number cancels itself out.

Only the missing number remains.

Example

```
nums = [3,0,1]

Start = 3

ans ^= 0 ^= 3
ans ^= 1 ^= 0
ans ^= 2 ^= 1

Remaining = 2
```

---

## What I Learned

- Sum formula

```
n*(n+1)/2
```

- Difference between expected sum and actual sum.
- XOR can also solve missing-number problems without extra memory.
- Both solutions run in O(n) time and O(1) space.