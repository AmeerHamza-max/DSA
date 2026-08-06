# 844. Backspace String Compare

## Problem Statement

Given two strings `s` and `t`, return `true` if they are equal after typing them into empty text editors.

The character `#` represents a **backspace**, which removes the previously typed character (if any).

---

## Examples

### Example 1

**Input**

```text
s = "ab#c"
t = "ad#c"
```

**Output**

```text
true
```

**Explanation**

```
ab#c -> ac
ad#c -> ac
```

Both strings become `"ac"`.

---

### Example 2

**Input**

```text
s = "ab##"
t = "c#d#"
```

**Output**

```text
true
```

**Explanation**

```
ab## -> ""
c#d# -> ""
```

Both strings become empty.

---

### Example 3

**Input**

```text
s = "a#c"
t = "b"
```

**Output**

```text
false
```

**Explanation**

```
a#c -> c
b   -> b
```

`"c"` and `"b"` are different.

---

# Approach

We simulate typing in a text editor.

* Create two vectors.
* Traverse string `s`.

  * If the character is not `#`, push it into the vector.
  * If the character is `#`, remove the last character if the vector is not empty.
* Repeat the same process for string `t`.
* Compare both vectors.
* If they are equal, return `true`; otherwise, return `false`.

---

# Algorithm

1. Create two empty vectors.
2. Traverse `s`.
3. Push normal characters.
4. On `#`, pop the last character if the vector is not empty.
5. Repeat the same process for `t`.
6. Compare both vectors.
7. Return the comparison result.

---

# Code

```cpp
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> arr1;
        vector<char> arr2;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '#') {
                arr1.push_back(s[i]);
            } else {
                if (!arr1.empty()) {
                    arr1.pop_back();
                }
            }
        }

        for (int i = 0; i < t.length(); i++) {
            if (t[i] != '#') {
                arr2.push_back(t[i]);
            } else {
                if (!arr2.empty()) {
                    arr2.pop_back();
                }
            }
        }

        return arr1 == arr2;
    }
};
```

---

# Complexity Analysis

* **Time Complexity:** `O(n + m)`

  * Each string is traversed once.

* **Space Complexity:** `O(n + m)`

  * Two vectors are used to store the processed strings.

---

# Key Learning

* Learned how to simulate a text editor using a vector.
* Practiced using `push_back()` and `pop_back()`.
* Learned to handle backspace (`#`) operations safely using `empty()`.
* Learned that vectors can be compared directly using `==`.
* Understood how to solve string simulation problems.

---

## LeetCode

* **Problem:** 844. Backspace String Compare
* **Difficulty:** Easy
* **Topics:** String, Stack, Two Pointers
