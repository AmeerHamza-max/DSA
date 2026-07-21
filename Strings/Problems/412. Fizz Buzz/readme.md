# Fizz Buzz (LeetCode 412)

## Overview

This C++ solution solves the **Fizz Buzz** problem by iterating through numbers from **1 to n** and applying simple divisibility rules.

* If a number is divisible by both **3** and **5**, add `"FizzBuzz"`.
* If it is divisible only by **3**, add `"Fizz"`.
* If it is divisible only by **5**, add `"Buzz"`.
* Otherwise, convert the number to a string and add it to the result.

---

# Problem Statement

Given an integer `n`, return a string array `answer` (1-indexed) where:

* `answer[i] == "FizzBuzz"` if `i` is divisible by both **3** and **5**.
* `answer[i] == "Fizz"` if `i` is divisible by **3**.
* `answer[i] == "Buzz"` if `i` is divisible by **5**.
* `answer[i] == i` (as a string) if none of the above conditions are true.

---

## Examples

### Example 1

**Input**

```text
n = 3
```

**Output**

```text
["1","2","Fizz"]
```

---

### Example 2

**Input**

```text
n = 5
```

**Output**

```text
["1","2","Fizz","4","Buzz"]
```

---

### Example 3

**Input**

```text
n = 15
```

**Output**

```text
["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
```

---

# Approach

1. Create an empty vector of strings named `ans`.
2. Iterate from **1** to **n**.
3. Check if the current number is divisible by both **3** and **5**.

   * Add `"FizzBuzz"`.
4. Otherwise, check if it is divisible by **3**.

   * Add `"Fizz"`.
5. Otherwise, check if it is divisible by **5**.

   * Add `"Buzz"`.
6. Otherwise, convert the number into a string using `to_string()` and add it to the vector.
7. Return the completed vector.

---

# Algorithm

1. Initialize an empty `vector<string>`.
2. Loop from `i = 1` to `n`.
3. Apply the divisibility conditions:

   * `i % 3 == 0 && i % 5 == 0`
   * `i % 3 == 0`
   * `i % 5 == 0`
4. Store the appropriate string in the vector.
5. Return the vector.

---

# Dry Run

### Input

```text
n = 15
```

| Number | Condition          | Added to Vector |
| -----: | ------------------ | --------------- |
|      1 | None               | "1"             |
|      2 | None               | "2"             |
|      3 | Divisible by 3     | "Fizz"          |
|      4 | None               | "4"             |
|      5 | Divisible by 5     | "Buzz"          |
|      6 | Divisible by 3     | "Fizz"          |
|      7 | None               | "7"             |
|      8 | None               | "8"             |
|      9 | Divisible by 3     | "Fizz"          |
|     10 | Divisible by 5     | "Buzz"          |
|     11 | None               | "11"            |
|     12 | Divisible by 3     | "Fizz"          |
|     13 | None               | "13"            |
|     14 | None               | "14"            |
|     15 | Divisible by 3 & 5 | "FizzBuzz"      |

### Final Output

```text
["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
```

---

# C++ Solution

```cpp
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;

        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                ans.push_back("FizzBuzz");
            }
            else if (i % 3 == 0) {
                ans.push_back("Fizz");
            }
            else if (i % 5 == 0) {
                ans.push_back("Buzz");
            }
            else {
                ans.push_back(to_string(i));
            }
        }

        return ans;
    }
};
```

---

# Time Complexity

The loop runs exactly **n** times.

**Time Complexity:** **O(n)**

---

# Space Complexity

The answer vector stores **n** strings.

**Space Complexity:** **O(n)**

---

# Concepts Used

* Vector
* String
* `to_string()`
* Modulus Operator (`%`)
* Conditional Statements (`if`, `else if`, `else`)
* Iteration (`for` loop)

---

# Why This Solution Works

* Every number from **1** to **n** is processed exactly once.
* The condition for `"FizzBuzz"` is checked first to avoid missing numbers divisible by both **3** and **5**.
* Numbers that are not divisible by **3** or **5** are converted into strings using `to_string()`.
* The algorithm is simple, efficient, and satisfies all problem requirements.

---

# Test Cases

| Input | Output                                                                                      |
| ----: | ------------------------------------------------------------------------------------------- |
|     3 | `["1","2","Fizz"]`                                                                          |
|     5 | `["1","2","Fizz","4","Buzz"]`                                                               |
|    10 | `["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz"]`                                  |
|    15 | `["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]` |

---

# Conclusion

This solution efficiently generates the Fizz Buzz sequence using a single loop and simple divisibility checks. It runs in **O(n)** time and uses **O(n)** extra space to store the resulting strings.
