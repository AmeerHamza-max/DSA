# Repeated Substring Pattern (LeetCode 459)

## Problem Statement

Given a string `s`, determine whether it can be formed by repeating one of its substrings multiple times.

Return:

- `true` if the string is made by repeating a substring.
- `false` otherwise.

---

## Examples

### Example 1

**Input**

```text
s = "abab"
```

**Output**

```text
true
```

**Explanation**

The substring `"ab"` is repeated 2 times.

---

### Example 2

**Input**

```text
s = "aba"
```

**Output**

```text
false
```

**Explanation**

No substring can be repeated to form the original string.

---

### Example 3

**Input**

```text
s = "abcabcabcabc"
```

**Output**

```text
true
```

**Explanation**

The string can be formed by:

- `"abc"` repeated 4 times, or
- `"abcabc"` repeated 2 times.

---

# Approach

The idea is to try every possible substring length from `1` to `n/2`, where `n` is the length of the string.

For each possible length:

1. Check if the substring length divides the string length.
2. Take the first `len` characters as the candidate substring.
3. Repeat this substring enough times to match the original string length.
4. Compare the newly formed string with the original string.
5. If both are equal, return `true`.
6. If no valid substring is found, return `false`.

---

# Algorithm

1. Find the length `n` of the string.
2. Iterate `len` from `1` to `n / 2`.
3. If `n % len != 0`, skip this length.
4. Extract the first `len` characters.
5. Repeat the substring `n / len` times.
6. Compare the generated string with the original.
7. If they match, return `true`.
8. Otherwise, continue checking.
9. If the loop finishes, return `false`.

---

# Dry Run

## Input

```text
s = "abab"
```

### Step 1

```
n = 4
```

### Try len = 1

```
Substring = "a"

Repeated String = "aaaa"

"aaaa" != "abab"
```

Continue.

### Try len = 2

```
Substring = "ab"

Repeated String = "abab"

"abab" == "abab"
```

Return

```text
true
```

---

## Input

```text
s = "aba"
```

```
n = 3
```

Only possible length is `1`.

```
Substring = "a"

Repeated String = "aaa"

"aaa" != "aba"
```

No valid substring found.

Return

```text
false
```

---

# Code

```cpp
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();

        for (int len = 1; len <= n / 2; len++) {

            if (n % len != 0)
                continue;

            string sub = s.substr(0, len);
            string temp = "";

            for (int i = 0; i < n / len; i++) {
                temp += sub;
            }

            if (temp == s)
                return true;
        }

        return false;
    }
};
```

---

# Time Complexity

### Outer Loop

The outer loop checks every possible substring length.

```
O(n)
```

### Inner Loop

For each valid substring length, we may construct a new string of length `n`.

```
O(n)
```

### Overall Time Complexity

```
O(n²)
```

---

# Space Complexity

A temporary string of length `n` is created.

```
O(n)
```

---

# Key Concepts Learned

- String manipulation
- `substr()` function
- Divisibility check using `%`
- Nested loops
- Pattern matching
- Brute Force approach
- Time and Space Complexity analysis

---

# Constraints

- `1 <= s.length <= 10⁴`
- `s` consists of lowercase English letters.

---

# Conclusion

This solution checks every possible substring that could build the original string. If repeating that substring reconstructs the original string exactly, the answer is `true`; otherwise, it is `false`.

Although this brute-force approach has a time complexity of **O(n²)**, it is easy to understand and is accepted on LeetCode. A more optimized **O(n)** solution exists using the `(s + s)` string trick.