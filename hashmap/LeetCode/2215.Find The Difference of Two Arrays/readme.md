# LeetCode 2215 - Find the Difference of Two Arrays

## Problem Statement

Given two 0-indexed integer arrays `nums1` and `nums2`, return a list `answer` of size 2 where:

- `answer[0]` contains all **distinct** integers in `nums1` that are **not present** in `nums2`.
- `answer[1]` contains all **distinct** integers in `nums2` that are **not present** in `nums1`.

The order of the integers does not matter.

---

## Example 1

### Input

```cpp
nums1 = [1,2,3]
nums2 = [2,4,6]
```

### Output

```cpp
[[1,3],[4,6]]
```

### Explanation

- `1` and `3` are present in `nums1` but not in `nums2`.
- `4` and `6` are present in `nums2` but not in `nums1`.

---

## Example 2

### Input

```cpp
nums1 = [1,2,3,3]
nums2 = [1,1,2,2]
```

### Output

```cpp
[[3],[]]
```

### Explanation

- `3` appears twice in `nums1`, but it should appear only once in the answer.
- Every element of `nums2` exists in `nums1`.

---

# Brute Force Approach

1. Traverse every element of `nums1`.
2. Search that element in `nums2`.
3. If it is not found, check whether it already exists in the answer vector.
4. If it does not exist, push it into the answer.
5. Repeat the same process for `nums2`.

---

# Algorithm

```text
Create ans1 and ans2

For every element in nums1
    Search it in nums2
    If not found
        Check duplicate in ans1
        If not duplicate
            Push into ans1

For every element in nums2
    Search it in nums1
    If not found
        Check duplicate in ans2
        If not duplicate
            Push into ans2

Return {ans1, ans2}
```

---

# Dry Run

### Input

```cpp
nums1 = [1,2,3]
nums2 = [2,4,5]
```

### First Answer

Check `nums1`

| Element | Present in nums2? | Add |
|---------|-------------------|-----|
| 1 | No | ✅ |
| 2 | Yes | ❌ |
| 3 | No | ✅ |

Result

```cpp
ans1 = [1,3]
```

---

### Second Answer

Check `nums2`

| Element | Present in nums1? | Add |
|---------|-------------------|-----|
| 2 | Yes | ❌ |
| 4 | No | ✅ |
| 5 | No | ✅ |

Result

```cpp
ans2 = [4,5]
```

---

# Time Complexity

Searching each element in the other array:

```text
O(n × m)
```

Checking duplicates:

```text
O(n² + m²)
```

Overall Worst Case:

```text
O(n × m + n² + m²)
```

---

# Space Complexity

```text
O(n + m)
```

Used for storing the answer vectors.

---

# Optimal Approach (Using unordered_set)

Instead of searching every element repeatedly:

1. Store all elements of `nums1` in an `unordered_set`.
2. Store all elements of `nums2` in another `unordered_set`.
3. Traverse `set1` and add elements not present in `set2`.
4. Traverse `set2` and add elements not present in `set1`.

Since a set automatically removes duplicates, no extra duplicate checking is required.

---

# Optimal Algorithm

```text
Create set1 from nums1
Create set2 from nums2

For each element in set1
    If element not in set2
        Add to ans1

For each element in set2
    If element not in set1
        Add to ans2

Return {ans1, ans2}
```

---

# Optimal Time Complexity

```text
O(n + m)
```

---

# Optimal Space Complexity

```text
O(n + m)
```

---

# Concepts Used

- Nested Loops
- Linear Search
- Boolean Flag (`found`)
- Duplicate Checking
- Vectors
- `unordered_set`
- Hashing

---

# What I Learned

- Do **not** insert an element every time a comparison fails.
- First search the entire second array.
- Use a `found` flag to determine whether an element exists.
- Push the element **after** the inner loop finishes.
- Handle duplicate values before inserting into the answer.
- `unordered_set` provides a much cleaner and more efficient solution.

---

# LeetCode

**Problem Number:** 2215

**Problem Name:** Find the Difference of Two Arrays

**Difficulty:** Easy