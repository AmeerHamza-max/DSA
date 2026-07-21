# 229. Majority Element II

## Problem

Given an integer array `nums`.

Return all elements that appear **more than ⌊n/3⌋ times**.

The answer can contain **at most two elements**.

---

## Example 1

Input

```text
nums = [3,2,3]
```

Output

```text
[3]
```

---

## Example 2

Input

```text
nums = [1]
```

Output

```text
[1]
```

---

## Example 3

Input

```text
nums = [1,2]
```

Output

```text
[1,2]
```

---

# Observation

For Majority Element I

```
> n/2
```

there can be only **1** majority element.

For Majority Element II

```
> n/3
```

there can be **at most 2** majority elements.

Example

```
n = 9

Need > 3 occurrences.
```

Possible

```
4
4
1
```

Impossible

```
4
4
4

Total = 12 > 9
```

So we only need **2 candidates**.

---

# Boyer-Moore Voting Algorithm

Maintain

```
candidate1
candidate2

count1
count2
```

---

## Rules

For every number

### Case 1

Matches candidate1

```
count1++
```

---

### Case 2

Matches candidate2

```
count2++
```

---

### Case 3

count1 == 0

Choose new candidate1

```
candidate1 = num
count1 = 1
```

---

### Case 4

count2 == 0

Choose new candidate2

```
candidate2 = num
count2 = 1
```

---

### Case 5

Matches neither

Decrease both counts.

```
count1--
count2--
```

---

After first pass

We only have **possible candidates**.

Need another traversal to verify.

---

# Algorithm

### First Pass

Find two candidates.

### Second Pass

Count their actual occurrences.

### Return

Candidates whose frequency is

```
> n/3
```

---

# Dry Run

Input

```text
nums = [3,2,3]
```

Initially

```
candidate1 = 0
candidate2 = 1

count1 = 0
count2 = 0
```

---

Number = 3

```
count1 == 0

candidate1 = 3

count1 = 1
```

---

Number = 2

```
count2 == 0

candidate2 = 2

count2 = 1
```

---

Number = 3

Matches candidate1

```
count1 = 2
```

First pass

```
candidate1 = 3
candidate2 = 2
```

---

Verification

```
3 appears 2 times

2 appears 1 time

n = 3

Need > 1
```

Answer

```
[3]
```

---

# Code

```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int candidate1 = 0, candidate2 = 1;
        int count1 = 0, count2 = 0;

        for (int num : nums) {

            if (num == candidate1)
                count1++;

            else if (num == candidate2)
                count2++;

            else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            }

            else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            }

            else {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;

        for (int num : nums) {

            if (num == candidate1)
                count1++;

            else if (num == candidate2)
                count2++;
        }

        vector<int> ans;

        if (count1 > nums.size() / 3)
            ans.push_back(candidate1);

        if (count2 > nums.size() / 3)
            ans.push_back(candidate2);

        return ans;
    }
};
```

---

# Complexity

Let

```
n = nums.size()
```

Time Complexity

```
O(n)
```

Two traversals.

Space Complexity

```
O(1)
```

Only a few variables.

---

# Why Verification is Needed?

The first pass only finds **possible candidates**.

Example

```
nums = [1,2,3,4]
```

The algorithm will still end with some candidates, but none appear more than `n/3`.

So we must count again to confirm.

---

# Key Learning

- If threshold is `> n/2`, maintain **1 candidate**.
- If threshold is `> n/3`, maintain **2 candidates**.
- First pass gives **possible candidates**.
- Second pass verifies their actual frequencies.
- This is an extension of the Boyer-Moore Voting Algorithm.

---

# Interview Tip

Remember this pattern:

| Condition | Maximum Majority Elements | Candidates Needed |
|-----------|---------------------------:|------------------:|
| `> n/2` | 1 | 1 |
| `> n/3` | 2 | 2 |
| `> n/k` | `k - 1` | `k - 1` |

This generalized Boyer-Moore idea is a common interview topic for frequency-based array problems.