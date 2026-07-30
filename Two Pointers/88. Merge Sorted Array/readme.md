# 88. Merge Sorted Array

## Problem Statement

You are given two sorted integer arrays `nums1` and `nums2`.

- `nums1` has a size of `m + n`.
- The first `m` elements of `nums1` are valid.
- The last `n` elements are `0` and are only placeholders.
- `nums2` contains `n` sorted elements.

Merge `nums2` into `nums1` so that `nums1` becomes one sorted array.

---

## Example

### Input

```text
nums1 = [1,2,3,0,0,0]
m = 3

nums2 = [2,5,6]
n = 3
```

### Output

```text
[1,2,2,3,5,6]
```

---

# Approach (Three Pointers)

Instead of merging from the beginning, we merge from the **end** of the array.

### Why merge from the end?

The last `n` positions of `nums1` are empty (filled with `0` as placeholders).

If we start merging from the front, we may overwrite elements that we still need to compare.

By starting from the back, we use the empty space first and avoid losing any data.

---

## Pointers Used

We use three pointers.

```text
i = m - 1
```

Points to the last valid element of `nums1`.

```text
j = n - 1
```

Points to the last element of `nums2`.

```text
k = m + n - 1
```

Points to the last index of `nums1`.

---

## Algorithm

1. Initialize three pointers:
   - `i = m - 1`
   - `j = n - 1`
   - `k = m + n - 1`

2. Compare `nums1[i]` and `nums2[j]`.

3. Place the larger element at `nums1[k]`.

4. Move the corresponding pointer (`i` or `j`) backward.

5. Move `k` backward.

6. Repeat until one array is exhausted.

7. If elements remain in `nums2`, copy them into `nums1`.

---

## Dry Run

### Initial State

```text
nums1 = [1,2,3,0,0,0]
nums2 = [2,5,6]

i = 2
j = 2
k = 5
```

---

### Step 1

Compare

```text
3 and 6
```

6 is larger.

```text
nums1 = [1,2,3,0,0,6]
```

Move

```text
j--
k--
```

---

### Step 2

Compare

```text
3 and 5
```

5 is larger.

```text
nums1 = [1,2,3,0,5,6]
```

Move

```text
j--
k--
```

---

### Step 3

Compare

```text
3 and 2
```

3 is larger.

```text
nums1 = [1,2,3,3,5,6]
```

Move

```text
i--
k--
```

---

### Step 4

Compare

```text
2 and 2
```

Copy either value.

```text
nums1 = [1,2,2,3,5,6]
```

Move

```text
j--
k--
```

`j` becomes `-1`, so the algorithm stops.

---

## Why do we only copy remaining elements of nums2?

```cpp
while (j >= 0)
```

If `nums2` still has elements left, they must be copied into `nums1`.

We do **not** need

```cpp
while (i >= 0)
```

because the remaining elements of `nums1` are already in their correct positions.

---

## C++ Solution

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {

            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            }
            else {
                nums1[k] = nums2[j];
                j--;
            }

            k--;
        }

        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};
```

---

# Time Complexity

```text
O(m + n)
```

Each element is visited at most once.

---

# Space Complexity

```text
O(1)
```

No extra array is used.

---

# Key Learning Points

- Use **Three Pointers** (`i`, `j`, `k`).
- Always compare the last valid elements of both arrays.
- Fill `nums1` from the **back**.
- Decrease `k` after every insertion.
- Copy remaining elements of `nums2` if any are left.
- No need to copy remaining elements of `nums1` because they are already in the correct position.

---

# Interview Tip

- Brute Force Approach: **O((m+n) log(m+n))** (merge then sort)
- Optimal Two Pointer Approach: **O(m+n)** ✅
- Space Complexity: **O(1)**

This is the expected interview solution.