# LeetCode 1929 - Concatenation of Array

## Problem Statement

Given an integer array `nums` of length `n`, create an array `ans` of length `2n` where:

```cpp
ans[i] = nums[i]
ans[i + n] = nums[i]
```

Return the concatenated array.

---

## Approach Used

### Vector Duplication using `insert()`

The idea is to first copy all elements of the original array into a new vector `ans`. After that, we append the same elements again at the end of the vector using the STL `insert()` function.

### Steps

1. Create an empty vector `ans`.
2. Traverse the input array `nums`.
3. Push each element into `ans`.
4. Use `insert()` to append the entire contents of `ans` to its end.
5. Return the resulting vector.

---

## Code

```cpp
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            ans.push_back(nums[i]);
        }

        ans.insert(ans.end(), ans.begin(), ans.end());

        return ans;
    }
};
```

---

## Example

### Input

```cpp
nums = [1,2,1]
```

### Process

After copying:

```cpp
ans = [1,2,1]
```

After insertion:

```cpp
ans = [1,2,1,1,2,1]
```

### Output

```cpp
[1,2,1,1,2,1]
```

---

## Time Complexity

* Copying elements: `O(n)`
* Inserting duplicate elements: `O(n)`

**Overall Time Complexity:** `O(n)`

---

## Space Complexity

A new vector of size `2n` is created.

**Space Complexity:** `O(n)`

---

## STL Functions Used

### `push_back()`

Adds an element to the end of the vector.

```cpp
ans.push_back(nums[i]);
```

### `insert()`

Appends a range of elements into a vector.

```cpp
ans.insert(ans.end(), ans.begin(), ans.end());
```

This inserts all elements from `ans.begin()` to `ans.end()` at the end of `ans`.

---

## Key Learning

* How to use `vector::push_back()`
* How to use `vector::insert()`
* Concatenating arrays using STL vectors
* Understanding dynamic array growth in C++
