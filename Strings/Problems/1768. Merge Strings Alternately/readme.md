# Merge Strings Alternately (LeetCode 1768)

## Overview

This C++ solution merges two strings by taking one character alternately from each string. If one string is longer than the other, the remaining characters are appended at the end of the merged string.

---

## Problem Statement

You are given two strings `word1` and `word2`.

Merge the strings by adding letters in alternating order, starting with `word1`.

If one string is longer than the other, append the remaining letters to the end of the merged string.

### Example 1

**Input**
```text
word1 = "abc"
word2 = "pqr"
```

**Output**
```text
apbqcr
```

---

### Example 2

**Input**
```text
word1 = "ab"
word2 = "pqrs"
```

**Output**
```text
apbqrs
```

---

### Example 3

**Input**
```text
word1 = "abcd"
word2 = "pq"
```

**Output**
```text
apbqcd
```

---

## Approach

1. Create an empty string `ans`.
2. Traverse both strings using a single loop.
3. During each iteration:
   - If the current index exists in `word1`, append that character.
   - If the current index exists in `word2`, append that character.
4. Continue until all characters from both strings are processed.
5. Return the merged string.

---

## Algorithm

1. Initialize an empty string `ans`.
2. Loop from `0` until the maximum length of the two strings.
3. If the current index is valid for `word1`, append `word1[i]` to `ans`.
4. If the current index is valid for `word2`, append `word2[i]` to `ans`.
5. Return the final merged string.

---

## Dry Run

### Input

```text
word1 = "abc"
word2 = "pqr"
```

| Iteration | Character from word1 | Character from word2 | Result |
|-----------|----------------------|----------------------|--------|
| 0 | a | p | ap |
| 1 | b | q | apbq |
| 2 | c | r | apbqcr |

### Final Output

```text
apbqcr
```

---

## C++ Solution

```cpp
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";

        for (int i = 0; i < word1.size() || i < word2.size(); i++) {
            if (i < word1.size()) {
                ans += word1[i];
            }

            if (i < word2.size()) {
                ans += word2[i];
            }
        }

        return ans;
    }
};
```

---

## Time Complexity

The loop runs until the longer string is completely traversed.

**Time Complexity:** **O(max(n, m))**

Where:
- `n` = length of `word1`
- `m` = length of `word2`

---

## Space Complexity

An extra string is used to store the merged result.

**Space Complexity:** **O(n + m)**

Since the resulting string contains all characters from both input strings.

---

## Key Concepts Used

- Strings
- Iteration
- Conditional Statements
- String Concatenation (`+=`)
- Greedy Traversal

---

## Why This Solution Works

- Characters are added alternately from both strings.
- Boundary checks prevent out-of-range access.
- Remaining characters from the longer string are automatically appended.
- Efficient and easy to understand.

---

## Output Examples

| word1 | word2 | Output |
|--------|--------|--------|
| `"abc"` | `"pqr"` | `"apbqcr"` |
| `"ab"` | `"pqrs"` | `"apbqrs"` |
| `"abcd"` | `"pq"` | `"apbqcd"` |
| `"a"` | `"xyz"` | `"axyz"` |
| `"hello"` | `"w"` | `"hwello"` |

---

## Conclusion

This solution efficiently merges two strings by alternating their characters while safely handling strings of different lengths. It is an optimal solution with **O(max(n, m))** time complexity and **O(n + m)** space complexity.