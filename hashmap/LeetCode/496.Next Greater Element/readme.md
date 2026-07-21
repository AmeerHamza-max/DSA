# Next Greater Element I

## LeetCode

**Problem #496 - Next Greater Element I**

---

# Problem Statement

You are given two arrays:

- `nums1`
- `nums2`

`nums1` is a subset of `nums2`.

For every element in `nums1`, find its **Next Greater Element** in `nums2`.

The **Next Greater Element** is the **first greater element on the right side** of the current element.

If there is no greater element, return `-1`.

---

# Example

## Input

```text
nums1 = [4,1,2]

nums2 = [1,3,4,2]
```

## Output

```text
[-1,3,-1]
```

---

# Explanation

### Element = 4

```text
nums2

1 3 4 2
    ^
```

Right side:

```text
2
```

No greater element.

Answer:

```text
-1
```

---

### Element = 1

```text
nums2

1 3 4 2
^
```

Right side:

```text
3 4 2
```

The first greater element is

```text
3
```

Answer:

```text
3
```

---

### Element = 2

```text
nums2

1 3 4 2
      ^
```

Right side:

```text
(empty)
```

Answer

```text
-1
```

---

Final Answer

```text
[-1,3,-1]
```

---

# Brute Force Approach

For every element in `nums1`

↓

Find that element inside `nums2`

↓

Start checking the elements on its right

↓

If you find the first greater element

↓

Store it

↓

Otherwise store `-1`

---

# Algorithm

1. Create an empty answer vector.
2. Traverse every element of `nums1`.
3. Find that element in `nums2`.
4. From the next index, search toward the end.
5. If a greater element is found:
   - Store it.
   - Stop searching.
6. If no greater element exists:
   - Store `-1`.
7. Return the answer vector.

---

# Dry Run

```text
nums1 = [2,4]

nums2 = [1,2,3,4]
```

---

### Find 2

```text
1 2 3 4
  ^
```

Right side

```text
3 4
```

First greater

```text
3
```

Store

```text
3
```

---

### Find 4

```text
1 2 3 4
      ^
```

Right side

```text
(empty)
```

Store

```text
-1
```

Final Answer

```text
[3,-1]
```

---

# C++ Solution (Brute Force)

```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans;

        for (int i = 0; i < nums1.size(); i++) {

            int nextGreater = -1;

            // Find nums1[i] in nums2
            for (int j = 0; j < nums2.size(); j++) {

                if (nums1[i] == nums2[j]) {

                    // Search on the right side
                    for (int k = j + 1; k < nums2.size(); k++) {

                        if (nums2[k] > nums2[j]) {
                            nextGreater = nums2[k];
                            break;
                        }
                    }

                    break;
                }
            }

            ans.push_back(nextGreater);
        }

        return ans;
    }
};
```

---

# Time Complexity

```text
O(n × m)
```

- `n = nums1.size()`
- `m = nums2.size()`

For every element of `nums1`, we may traverse almost the entire `nums2`.

---

# Space Complexity

```text
O(1)
```

Ignoring the output array.

---

# Key Learning

- Understand the meaning of **Next Greater Element**.
- The next greater element must be:
  - Greater than the current element.
  - On the **right side**.
  - The **first** greater element encountered.
- First solve the problem using the **Brute Force** approach.
- The optimal solution uses **Monotonic Stack + HashMap** with **O(n)** time complexity.

---

# Interview Tip

Always solve the problem in this order:

1. Understand the question.
2. Write the Brute Force solution.
3. Optimize it if asked.

Writing a correct brute-force solution is much better than not solving the problem at all.

---

# Tags

- Array
- Stack
- Monotonic Stack
- Hash Table
- Brute Force

---

# LeetCode

**496. Next Greater Element I**