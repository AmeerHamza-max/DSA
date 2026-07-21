# Two Sum

## Problem Statement

Given an array of integers `nums` and an integer `target`, return the indices of the two numbers such that they add up to the target.

You may assume that each input has **exactly one solution**, and you may not use the same element twice.

You can return the answer in any order.

---

## Example 1

**Input**

```text
nums = [2,7,11,15]
target = 9
```

**Output**

```text
[0,1]
```

**Explanation**

```text
nums[0] + nums[1] = 2 + 7 = 9
```

---

## Example 2

**Input**

```text
nums = [3,2,4]
target = 6
```

**Output**

```text
[1,2]
```

---

## Example 3

**Input**

```text
nums = [3,3]
target = 6
```

**Output**

```text
[0,1]
```

---

## Approach (Brute Force)

1. Traverse the array using the first loop.
2. For each element, compare it with every remaining element.
3. If the sum of two elements equals the target:
   - Store their indices.
   - Stop searching.
4. Return the indices.

---

## Algorithm

1. Create an empty vector `ans`.
2. Run the outer loop from `0` to `n - 2`.
3. Run the inner loop from `i + 1` to `n - 1`.
4. Check if:

```cpp
nums[i] + nums[j] == target
```

5. If true:
   - Push both indices into `ans`.
   - Break the loops.
6. Return the answer.

---

## C++ Solution (Brute Force)

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> ans;

        for (int i = 0; i < nums.size() - 1; i++) {

            for (int j = i + 1; j < nums.size(); j++) {

                if (nums[i] + nums[j] == target) {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }

        return ans;
    }
};
```

---

## Dry Run

### Input

```text
nums = [3,2,4]
target = 6
```

### Iteration 1

```text
i = 0
j = 1

3 + 2 = 5 ❌
```

```text
j = 2

3 + 4 = 7 ❌
```

### Iteration 2

```text
i = 1
j = 2

2 + 4 = 6 ✅
```

Store indices:

```text
[1,2]
```

Return the answer.

---

## Complexity Analysis

### Time Complexity

```text
O(n²)
```

Because every element is compared with the remaining elements.

### Space Complexity

```text
O(1)
```

Only the output vector is used (excluding the returned answer).

---

## Key Learning

- Use **nested loops** to check every possible pair.
- The inner loop should start from `i + 1`.
- Compare:

```cpp
nums[i] + nums[j]
```

instead of adjacent elements.

- This is the **Brute Force** approach.
- The optimal solution uses an **unordered_map** and runs in **O(n)** time.

---

## Tags

- Array
- Hash Table
- Brute Force
- Two Pointers (Concept)
- LeetCode Easy

---

## LeetCode

**Problem #1 — Two Sum**