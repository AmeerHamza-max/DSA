# 1768. Merge Strings Alternately

## Problem Statement

You are given two strings `word1` and `word2`.

Merge the strings by adding letters in alternating order, starting with `word1`.

- If one string is longer than the other, append the remaining characters to the end of the merged string.

Return the merged string.

---

## Example 1

### Input

```text
word1 = "abc"
word2 = "pqr"
```

### Output

```text
"apbqcr"
```

---

## Example 2

### Input

```text
word1 = "ab"
word2 = "pqrs"
```

### Output

```text
"apbqrs"
```

### Explanation

Merge alternately until one string ends.

Remaining characters:

```text
rs
```

Append them to the answer.

---

## Example 3

### Input

```text
word1 = "abcd"
word2 = "pq"
```

### Output

```text
"apbqcd"
```

---

# Approach

We traverse both strings simultaneously.

At every index:

- Add one character from `word1` (if available).
- Add one character from `word2` (if available).

Continue until both strings are completely traversed.

---

# Step 1

Create an empty string.

```cpp
string ans = "";
```

---

# Step 2

Loop until both strings are finished.

```cpp
for(int i = 0; i < word1.size() || i < word2.size(); i++)
```

The loop continues as long as **either** string still has characters.

---

# Step 3

If `word1` still has a character,

append it.

```cpp
if(i < word1.size())
    ans += word1[i];
```

---

# Step 4

If `word2` still has a character,

append it.

```cpp
if(i < word2.size())
    ans += word2[i];
```

---

# Dry Run

### Input

```text
word1 = "abc"
word2 = "pqr"
```

Initially

```text
ans = ""
```

### i = 0

Append

```text
a
```

Append

```text
p
```

```text
ans = "ap"
```

---

### i = 1

Append

```text
b
```

Append

```text
q
```

```text
ans = "apbq"
```

---

### i = 2

Append

```text
c
```

Append

```text
r
```

```text
ans = "apbqcr"
```

Final Answer

```text
"apbqcr"
```

---

## Another Dry Run

### Input

```text
word1 = "ab"
word2 = "pqrs"
```

### i = 0

```text
ans = "ap"
```

### i = 1

```text
ans = "apbq"
```

### i = 2

`word1` is finished.

Append only

```text
r
```

```text
ans = "apbqr"
```

### i = 3

Append only

```text
s
```

```text
ans = "apbqrs"
```

Final Answer

```text
"apbqrs"
```

---

# Algorithm

1. Create an empty string `ans`.
2. Traverse both strings using one loop.
3. If `word1` has a character at index `i`, append it.
4. If `word2` has a character at index `i`, append it.
5. Return the merged string.

---

# C++ Solution

```cpp
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";

        for(int i = 0; i < word1.size() || i < word2.size(); i++) {

            if(i < word1.size()) {
                ans += word1[i];
            }

            if(i < word2.size()) {
                ans += word2[i];
            }
        }

        return ans;
    }
};
```

---

# Time Complexity

We visit each character exactly once.

```text
O(n + m)
```

where

- `n` = length of `word1`
- `m` = length of `word2`

---

# Space Complexity

The answer string stores all characters.

```text
O(n + m)
```

---

# Why This Works

- The loop continues until **both** strings are completely processed.
- Each iteration appends one character from each string (if available).
- The `if` conditions safely handle strings of different lengths.
- Remaining characters from the longer string are automatically appended.

---

# Key Takeaways

- Use a single loop with the condition:

```cpp
i < word1.size() || i < word2.size()
```

- Check the bounds of each string before accessing its characters.
- `+=` appends characters to the result string.
- This is the simplest and most efficient solution.

---

# LeetCode Link

https://leetcode.com/problems/merge-strings-alternately/