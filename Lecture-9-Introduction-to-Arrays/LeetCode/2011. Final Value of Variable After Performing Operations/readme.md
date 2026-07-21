# 2011. Final Value of Variable After Performing Operations

## Problem Statement

A variable `X` is initially `0`.

There are four possible operations:

* `++X` → Increment `X` by 1
* `X++` → Increment `X` by 1
* `--X` → Decrement `X` by 1
* `X--` → Decrement `X` by 1

Given an array `operations`, return the final value of `X` after performing all operations.

---

## Approach

Since each operation either increases or decreases the value of `X` by `1`, we can process the operations one by one and update the value of `X` accordingly.

### Algorithm

1. Initialize `x = 0`.
2. Traverse the `operations` array.
3. For each operation:

   * If the operation is `"++X"` or `"X++"`, increment `x`.
   * If the operation is `"--X"` or `"X--"`, decrement `x`.
4. Return the final value of `x`.

---

## Dry Run

### Input

```text
operations = ["--X", "X++", "X++"]
```

### Execution

```text
Initial x = 0

"--X" -> x = -1
"X++" -> x = 0
"X++" -> x = 1
```

### Output

```text
1
```

---

## Code

```cpp
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;

        for (auto op : operations) {
            if (op == "--X") {
                --x;
            }
            else if (op == "X++") {
                x++;
            }
            else if (op == "++X") {
                ++x;
            }
            else {
                x--;
            }
        }

        return x;
    }
};
```

---

## Complexity Analysis

### Time Complexity

```text
O(n)
```

We traverse the operations array exactly once.

### Space Complexity

```text
O(1)
```

Only a single variable `x` is used.

---

## Key Observation

* `"++X"` and `"X++"` both increase `x` by `1`.
* `"--X"` and `"X--"` both decrease `x` by `1`.
* The position of `++` or `--` does not matter for this problem since only the final value is required.

---

## Pattern

**Simulation**

We simply simulate the operations in the order they are given and maintain the current value of `X`.
