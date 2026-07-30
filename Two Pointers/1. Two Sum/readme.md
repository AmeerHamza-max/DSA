# Two Sum (LeetCode 1)

## Problem Statement

Given an array of integers `nums` and an integer `target`, return the **indices** of the two numbers such that they add up to the target.

- Exactly one valid solution exists.
- The same element cannot be used twice.
- Return the indices in any order.

---

## Example

### Example 1

**Input:**

```text
nums = [2,7,11,15]
target = 9
```

**Output:**

```text
[0,1]
```

**Explanation:**

```text
nums[0] + nums[1] = 2 + 7 = 9
```

---

## Approach (Hash Map)

We use an `unordered_map` to store:

```text
Key   -> Number
Value -> Index
```

### Steps

1. Create an empty hash map.
2. Traverse the array.
3. For each element, calculate:

```text
complement = target - nums[i]
```

4. Check whether the complement already exists in the map.
5. If it exists, return its stored index and the current index.
6. Otherwise, store the current number and its index in the map.
7. Continue until the answer is found.

---

## Dry Run

### Input

```text
nums = [2,7,11,15]
target = 9
```

### Iteration 1

Current Number:

```text
2
```

Complement:

```text
9 - 2 = 7
```

Map:

```text
{}
```

7 is not found.

Store:

```text
2 -> 0
```

---

### Iteration 2

Current Number:

```text
7
```

Complement:

```text
9 - 7 = 2
```

Map:

```text
2 -> 0
```

2 is found.

Return:

```text
[0,1]
```

---

## Algorithm

```text
Create an unordered_map.

For each element in the array:

    complement = target - current_number

    If complement exists in the map:
        Return {stored_index, current_index}

    Otherwise:
        Store current_number and its index.

Return empty vector.
```

---

## Time Complexity

```text
O(n)
```

Each element is visited only once.

---

## Space Complexity

```text
O(n)
```

The hash map stores up to `n` elements.

---

## C++ Solution

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {

            int complement = target - nums[i];

            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};
```

---

## Key Learning Points

- `unordered_map` stores data as **Key → Value** pairs.
- Store **Number → Index** in the hash map.
- Calculate the complement using:

```cpp
target - nums[i]
```

- `mp.find(key)` checks whether the key exists.
- `mp.end()` means the key was **not found**.
- `mp[complement]` returns the index where the complement was previously stored.

---

## Interview Tip

- Brute Force Approach: **O(n²)**
- Hash Map Approach: **O(n)** ✅ (Optimal)
- Two Pointer Approach works only after sorting, but sorting changes the original indices. Therefore, it is **not the optimal solution** for the original Two Sum problem.