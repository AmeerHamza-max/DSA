# 2956. Find Common Elements Between Two Arrays

## Problem

You are given two integer arrays:

- `nums1`
- `nums2`

Find:

- `answer1` = Number of indices in `nums1` whose value exists in `nums2`.
- `answer2` = Number of indices in `nums2` whose value exists in `nums1`.

Return

```text
[answer1, answer2]
```

---

## Example 1

Input

```text
nums1 = [2,3,2]
nums2 = [1,2]
```

Output

```text
[2,1]
```

Explanation

```
nums1

2 ✓
3 ✗
2 ✓

answer1 = 2
```

```
nums2

1 ✗
2 ✓

answer2 = 1
```

---

## Example 2

Input

```text
nums1 = [4,3,2,3,1]
nums2 = [2,2,5,2,3,6]
```

Output

```text
[3,4]
```

---

## Idea

The values are between **1 and 100**.

Instead of searching every time, create two boolean arrays.

```
present1[x]
```

means

```
Is x present in nums1?
```

Similarly,

```
present2[x]
```

means

```
Is x present in nums2?
```

Now checking whether a number exists becomes **O(1)**.

---

# Algorithm

### Step 1

Create two boolean arrays of size 101.

```
present1
present2
```

---

### Step 2

Mark every element of `nums1`.

Example

```
nums1 = [2,3,2]

present1[2] = true
present1[3] = true
```

---

### Step 3

Mark every element of `nums2`.

Example

```
nums2 = [1,2]

present2[1] = true
present2[2] = true
```

---

### Step 4

Traverse `nums1`.

If

```
present2[num] == true
```

increase `answer1`.

---

### Step 5

Traverse `nums2`.

If

```
present1[num] == true
```

increase `answer2`.

---

### Step 6

Return

```
{answer1, answer2}
```

---

# Dry Run

Input

```text
nums1 = [2,3,2]
nums2 = [1,2]
```

### Presence Arrays

```
present1

2 ✓
3 ✓
```

```
present2

1 ✓
2 ✓
```

---

Traverse nums1

```
2 ✓
3 ✗
2 ✓
```

```
answer1 = 2
```

---

Traverse nums2

```
1 ✗
2 ✓
```

```
answer2 = 1
```

Return

```text
[2,1]
```

---

# Code

```cpp
class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {

        vector<bool> present1(101, false);
        vector<bool> present2(101, false);

        for(int num : nums1){
            present1[num] = true;
        }

        for(int num : nums2){
            present2[num] = true;
        }

        int answer1 = 0;
        int answer2 = 0;

        for(int num : nums1){
            if(present2[num]){
                answer1++;
            }
        }

        for(int num : nums2){
            if(present1[num]){
                answer2++;
            }
        }

        return {answer1, answer2};
    }
};
```

---

# Complexity

Let

```
n = nums1.size()
m = nums2.size()
```

Time Complexity

```
O(n + m)
```

Space Complexity

```
O(101)
```

Since 101 is constant,

```
O(1)
```

---

# Key Learning

- Use a **presence array** when the value range is small.
- Checking whether an element exists becomes **O(1)**.
- Don't compare every element with every other element (`O(n × m)`).
- A boolean array is often simpler and faster than using a map or set for small ranges.

---

# Interview Tip

Whenever the constraints look like:

```text
1 <= value <= 100
```

or

```text
0 <= value <= 1000
```

Think of using a **frequency array** or **presence array** instead of nested loops or hash maps. It usually gives an **O(n)** solution with constant extra space.