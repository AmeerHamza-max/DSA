# 1754. Largest Merge Of Two Strings

## Problem Statement

You are given two strings `word1` and `word2`.

You want to create a new string called **merge**.

At each step:

- Remove the first character from either `word1` or `word2`.
- Append it to `merge`.

Continue until both strings become empty.

Return the **lexicographically largest** merge possible.

---

## Example 1

### Input

```text
word1 = "cabaa"
word2 = "bcaaa"
```

### Output

```text
"cbcabaaaaa"
```

---

## Example 2

### Input

```text
word1 = "abcabc"
word2 = "abdcaba"
```

### Output

```text
"abdcabcabcaba"
```

---

# What Does "Lexicographically Largest" Mean?

It means the string that would appear **later in dictionary order**.

Example:

```text
"b" > "a"
```

```text
"cab" > "baa"
```

```text
"apple" < "banana"
```

So we always try to place the larger character (or larger remaining substring) first.

---

# Approach (Greedy)

Simply comparing the current characters is **not enough**.

Example

```text
word1 = "abx"
word2 = "aba"
```

Current characters

```text
a == a
```

Which one should we take?

We compare the **remaining substrings**.

```text
"abx"
```

vs

```text
"aba"
```

Since

```text
"abx" > "aba"
```

take from `word1`.

---

# Algorithm

1. Initialize two pointers:

```text
i = 0
j = 0
```

2. While both strings have characters:

- Compare

```cpp
word1.substr(i)
```

and

```cpp
word2.substr(j)
```

- If the remaining part of `word1` is larger,
  append `word1[i]`.

- Otherwise,
  append `word2[j]`.

3. After one string finishes,

append all remaining characters from the other string.

4. Return the answer.

---

# Dry Run

### Input

```text
word1 = "cabaa"
word2 = "bcaaa"
```

Initially

```text
word1 = cabaa
word2 = bcaaa
```

Compare

```text
cabaa
```

and

```text
bcaaa
```

Since

```text
cabaa > bcaaa
```

Take

```text
c
```

Answer

```text
c
```

---

Now

```text
abaa
```

vs

```text
bcaaa
```

Since

```text
bcaaa > abaa
```

Take

```text
b
```

Answer

```text
cb
```

---

Now

```text
abaa
```

vs

```text
caaa
```

Take

```text
c
```

Answer

```text
cbc
```

Continue until both strings become empty.

Final Answer

```text
cbcabaaaaa
```

---

# C++ Solution

```cpp
class Solution {
public:
    string largestMerge(string word1, string word2) {

        string ans = "";
        int i = 0, j = 0;

        while (i < word1.size() && j < word2.size()) {

            if (word1.substr(i) > word2.substr(j)) {
                ans += word1[i++];
            } else {
                ans += word2[j++];
            }
        }

        while (i < word1.size()) {
            ans += word1[i++];
        }

        while (j < word2.size()) {
            ans += word2[j++];
        }

        return ans;
    }
};
```

---

# Time Complexity

In the above implementation,

`substr()` creates a new string during each comparison.

Worst-case complexity:

```text
O((n + m)²)
```

where:

- `n` = length of `word1`
- `m` = length of `word2`

---

# Space Complexity

Answer string:

```text
O(n + m)
```

Extra space due to `substr()`:

```text
O(n + m)
```

---

# Why This Works

- At every step, we choose the string whose **remaining suffix is lexicographically larger**.
- This greedy choice guarantees the final merged string is the largest possible.
- Once one string is exhausted, we simply append the rest of the other string.

---

# Key Takeaways

- Compare the **remaining substrings**, not just the current characters.
- A greedy strategy produces the optimal answer.
- The `substr()` solution is simple and easy to understand.
- Although accepted by LeetCode, it is not the most efficient because `substr()` creates temporary strings repeatedly.

---

# Better Optimization

Instead of using:

```cpp
word1.substr(i) > word2.substr(j)
```

you can compare the remaining characters directly using two pointers.

That reduces unnecessary string creation and improves performance.

---

# LeetCode Link

https://leetcode.com/problems/largest-merge-of-two-strings/