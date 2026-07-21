# 283. Move Zeroes

## Problem Statement

Given an integer array `nums`, move all `0`'s to the end of it while maintaining the relative order of the non-zero elements.

You must do this **in-place** without making a copy of the array.

---

## Example

### Input

```cpp id="a1"
nums = [0, 1, 0, 3, 12]
```

### Output

```cpp id="a2"
[1, 3, 12, 0, 0]
```

---

## Approach

We use a **two-pass technique with a write pointer**:

### Step 1: Move all non-zero elements forward

* Use a pointer `j` to track the position of the next non-zero element.
* Traverse the array and copy all non-zero values to the front.

### Step 2: Fill remaining positions with zero

* After placing all non-zero elements, fill the rest of the array with `0`.

---

## Algorithm

```text id="b1"
1. Initialize j = 0
2. Traverse array:
      If nums[i] != 0:
          nums[j] = nums[i]
          j++
3. Fill remaining positions with 0:
      while j < n:
          nums[j] = 0
          j++
```

---

## C++ Solution

```cpp id="c1"
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                nums[j] = nums[i];
                j++;
            }
        }

        while(j < n){
            nums[j] = 0;
            j++;
        }
    }
};
```

---

## Dry Run

### Input

```cpp id="d1"
[0, 1, 0, 3, 12]
```

### Step 1: Move non-zeros

```
[1, 3, 12, 3, 12]
```

### Step 2: Fill zeros

```
[1, 3, 12, 0, 0]
```

---

## Complexity Analysis

### Time Complexity

```
O(n)
```

### Space Complexity

```
O(1)
```

---

## Key Learnings

* Two-pointer technique (write pointer approach)
* In-place array manipulation
* Stable ordering of elements
* Efficient O(n) solution without extra space

---

## Important Insight

Instead of swapping elements randomly, we **overwrite using a tracking index (`j`)**, which ensures:

* Order is preserved
* No extra space is used
* Clean and efficient solution
