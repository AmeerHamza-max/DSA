# 2161. Partition Array According to Given Pivot

## Problem Statement

You are given an integer array `nums` and an integer `pivot`.

Rearrange the array such that:

1. All elements **less than** `pivot` come first.
2. All elements **equal to** `pivot` come next.
3. All elements **greater than** `pivot` come last.
4. The **relative order** of elements less than the pivot and greater than the pivot must remain the same.

Return the rearranged array.

---

## Example

### Input

```text
nums = [9,12,5,10,14,3,10]
pivot = 10
```

### Output

```text
[9,5,3,10,10,12,14]
```

---

## Approach

We create a new array `ans`.

Instead of trying to rearrange the original array, we traverse it **three times**.

### First Pass

Store every element that is **less than** the pivot.

```text
nums = [9,12,5,10,14,3,10]

ans = [9,5,3]
```

---

### Second Pass

Store every element **equal to** the pivot.

```text
ans = [9,5,3,10,10]
```

---

### Third Pass

Store every element **greater than** the pivot.

```text
ans = [9,5,3,10,10,12,14]
```

---

## Dry Run

### Input

```text
nums = [9,12,5,10,14,3,10]
pivot = 10
```

### Pass 1 (Less than Pivot)

| Element | Action |
|---------|--------|
| 9 | Add |
| 12 | Skip |
| 5 | Add |
| 10 | Skip |
| 14 | Skip |
| 3 | Add |
| 10 | Skip |

Result:

```text
ans = [9,5,3]
```

---

### Pass 2 (Equal to Pivot)

```text
ans = [9,5,3,10,10]
```

---

### Pass 3 (Greater than Pivot)

```text
ans = [9,5,3,10,10,12,14]
```

Final Answer:

```text
[9,5,3,10,10,12,14]
```

---

## Algorithm

1. Create an empty vector `ans`.
2. Traverse the array.
   - Insert every element smaller than `pivot`.
3. Traverse again.
   - Insert every element equal to `pivot`.
4. Traverse again.
   - Insert every element greater than `pivot`.
5. Return `ans`.

---

## C++ Solution

```cpp
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;

        // Elements smaller than pivot
        for (int num : nums) {
            if (num < pivot)
                ans.push_back(num);
        }

        // Elements equal to pivot
        for (int num : nums) {
            if (num == pivot)
                ans.push_back(num);
        }

        // Elements greater than pivot
        for (int num : nums) {
            if (num > pivot)
                ans.push_back(num);
        }

        return ans;
    }
};
```

---

## Time Complexity

Three traversals of the array.

```text
O(n)
```

---

## Space Complexity

We create a new vector to store the answer.

```text
O(n)
```

---

## Why This Works

- The first traversal keeps all elements smaller than the pivot in their original order.
- The second traversal places every pivot element together.
- The third traversal keeps all greater elements in their original order.
- Since we never change the order during each traversal, the required **stable ordering** is preserved.

---

## Key Takeaways

- Stable partitioning means **preserving the original order** of elements.
- Three simple traversals are enough to satisfy all conditions.
- Easy to understand and optimal with **O(n)** time.
- Extra space **O(n)** is acceptable for this problem.

---

## LeetCode Link

https://leetcode.com/problems/partition-array-according-to-given-pivot/
