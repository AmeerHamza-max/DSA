# 922. Sort Array By Parity II

## Problem

You are given an integer array `nums` where:

* Half of the elements are **even**.
* Half of the elements are **odd**.

Rearrange the array so that:

* Every **even index** contains an **even number**.
* Every **odd index** contains an **odd number**.

Return any valid array.

---

## Example

### Input

```cpp
nums = [4,2,5,7]
```

### Output

```cpp
[4,5,2,7]
```

Explanation:

* Index `0` → `4` (Even Index → Even Number) ✅
* Index `1` → `5` (Odd Index → Odd Number) ✅
* Index `2` → `2` (Even Index → Even Number) ✅
* Index `3` → `7` (Odd Index → Odd Number) ✅

---

# Approach

We create a new answer vector of the same size as `nums`.

We maintain two pointers:

* `evenIndex = 0` → Points to the next available even index.
* `oddIndex = 1` → Points to the next available odd index.

Now traverse the original array.

* If the current number is **even**, place it at `ans[evenIndex]` and move `evenIndex` by `2`.
* If the current number is **odd**, place it at `ans[oddIndex]` and move `oddIndex` by `2`.

Since the problem guarantees that half of the numbers are even and half are odd, both pointers will always remain within the array.

---

# Algorithm

1. Create an answer vector of size `n`.
2. Initialize:

   * `evenIndex = 0`
   * `oddIndex = 1`
3. Traverse the array.
4. If the number is even:

   * Place it at `ans[evenIndex]`.
   * Increment `evenIndex` by `2`.
5. Otherwise:

   * Place it at `ans[oddIndex]`.
   * Increment `oddIndex` by `2`.
6. Return the answer vector.

---

# Dry Run

### Input

```cpp
nums = [4,2,5,7]
```

Initially:

```text
ans = [_, _, _, _]

evenIndex = 0
oddIndex = 1
```

### Step 1

Current Number = 4 (Even)

```text
ans = [4, _, _, _]

evenIndex = 2
```

---

### Step 2

Current Number = 2 (Even)

```text
ans = [4, _, 2, _]

evenIndex = 4
```

---

### Step 3

Current Number = 5 (Odd)

```text
ans = [4, 5, 2, _]

oddIndex = 3
```

---

### Step 4

Current Number = 7 (Odd)

```text
ans = [4, 5, 2, 7]

oddIndex = 5
```

Final Answer:

```cpp
[4,5,2,7]
```

---

# Code

```cpp
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {

        vector<int> ans(nums.size());

        int evenIndex = 0;
        int oddIndex = 1;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] % 2 == 0) {
                ans[evenIndex] = nums[i];
                evenIndex += 2;
            } else {
                ans[oddIndex] = nums[i];
                oddIndex += 2;
            }
        }

        return ans;
    }
};
```

---

# Complexity Analysis

### Time Complexity

```
O(n)
```

We traverse the array only once.

---

### Space Complexity

```
O(n)
```

An additional vector of size `n` is used.

---

# Key Learning

* Use two pointers to track even and odd indices separately.
* `evenIndex` always moves by `2`.
* `oddIndex` always moves by `2`.
* Initialize the answer vector with the required size before assigning values by index.
* This is an efficient `O(n)` solution with straightforward implementation.
