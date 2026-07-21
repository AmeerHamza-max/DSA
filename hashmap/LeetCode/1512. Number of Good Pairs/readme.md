# LeetCode 1512 - Number of Good Pairs

## Problem
Given an integer array `nums`, return the number of **good pairs**.

A pair `(i, j)` is called **good** if:

- `nums[i] == nums[j]`
- `i < j`

---

## Approach (Using Hash Map)

### Idea

- Create a hash map (`unordered_map`) to store the frequency of every number.
- Traverse the array and count how many times each number appears.
- If a number appears `f` times, then the number of good pairs formed is:

\[
\frac{f \times (f - 1)}{2}
\]

- Add the result for every unique number.

---

## Why Formula Works?

Suppose a number appears:

- 2 times → 1 pair
- 3 times → 3 pairs
- 4 times → 6 pairs
- 5 times → 10 pairs

This follows the combination formula:

\[
^{f}C_{2} = \frac{f(f-1)}{2}
\]

because we are choosing any **2 indices** from `f` occurrences.

---

## Dry Run

### Input

```cpp
nums = [1,2,3,1,1,3]
```

### Frequency Map

| Number | Frequency |
|--------|-----------|
| 1 | 3 |
| 2 | 1 |
| 3 | 2 |

### Calculate Pairs

For `1`

```
3 × 2 / 2 = 3
```

For `2`

```
1 × 0 / 2 = 0
```

For `3`

```
2 × 1 / 2 = 1
```

### Total

```
3 + 0 + 1 = 4
```

Output:

```
4
```

---

## Algorithm

1. Create an empty hash map.
2. Count the frequency of every element.
3. Traverse the hash map.
4. For every frequency `f`, calculate:

```cpp
(f * (f - 1)) / 2
```

5. Add it to the answer.
6. Return the final count.

---

## Complexity Analysis

### Time Complexity

- Counting frequencies: **O(n)**
- Traversing map: **O(k)**

Overall:

```
O(n)
```

where `k` is the number of unique elements.

---

### Space Complexity

```
O(k)
```

where `k` is the number of unique elements stored in the hash map.

---

## C++ Code

```cpp
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> freq;

        for(int num : nums){
            freq[num]++;
        }

        int count = 0;

        for(auto it : freq){
            int f = it.second;
            count += (f * (f - 1)) / 2;
        }

        return count;
    }
};
```

---

## Key Learning

- Use `unordered_map` to count frequencies efficiently.
- If an element appears `f` times, the number of unique pairs is calculated using the combination formula:

```
fC2 = (f × (f - 1)) / 2
```

- This approach is much faster than checking every pair using nested loops (`O(n²)`).

---

## LeetCode

**Problem Number:** 1512

**Problem Name:** Number of Good Pairs

**Difficulty:** Easy

**Topic:** Array, Hash Map, Counting