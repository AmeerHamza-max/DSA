# 2000. Reverse Prefix of Word

## Problem Statement

Given a string `word` and a character `ch`, reverse the part of the string that starts from index `0` and ends at the **first occurrence** of `ch` (inclusive).

- If `ch` does not exist in the string, return the original string.

---

## Example 1

### Input

```text
word = "abcdefd"
ch = 'd'
```

### Output

```text
"dcbaefd"
```

### Explanation

The first occurrence of `'d'` is at index `3`.

Reverse:

```text
abcd
```

Result:

```text
dcbaefd
```

---

## Example 2

### Input

```text
word = "xyxzxe"
ch = 'z'
```

### Output

```text
"zxyxxe"
```

---

## Example 3

### Input

```text
word = "abcd"
ch = 'z'
```

### Output

```text
"abcd"
```

Explanation:

`'z'` is not present, so the string remains unchanged.

---

# Approach

We first locate the **first occurrence** of `ch`.

If it exists,

- reverse the substring from index `0` to that position.

Otherwise,

- return the original string.

The C++ STL provides two useful functions:

- `find()` → finds the first occurrence.
- `reverse()` → reverses a range.

---

# Step 1

Find the first occurrence of `ch`.

```cpp
int index = word.find(ch);
```

Example

```text
word = "abcdefd"

index = 3
```

---

# Step 2

Check if the character exists.

```cpp
if(index != string::npos)
```

`string::npos` means **not found**.

---

# Step 3

Reverse the prefix.

```cpp
reverse(word.begin(), word.begin() + index + 1);
```

Notice

```text
+1
```

because `reverse()` excludes the ending iterator.

---

# Dry Run

### Input

```text
word = "abcdefd"
ch = 'd'
```

Find index

```text
index = 3
```

Reverse

```text
abcd
```

After reverse

```text
dcba
```

Remaining part

```text
efd
```

Final Answer

```text
dcbaefd
```

---

## Another Dry Run

### Input

```text
word = "xyxzxe"
ch = 'z'
```

First occurrence

```text
index = 3
```

Reverse

```text
xyxz
```

After reverse

```text
zxyx
```

Remaining

```text
xe
```

Answer

```text
zxyxxe
```

---

## Another Example

### Input

```text
word = "abcd"
ch = 'z'
```

Find

```text
index = string::npos
```

Character not found.

Return

```text
abcd
```

---

# Algorithm

1. Find the first occurrence of `ch`.
2. If it exists:
   - Reverse the substring from index `0` to `index`.
3. Otherwise:
   - Return the original string.
4. Return the modified string.

---

# C++ Solution

```cpp
class Solution {
public:
    string reversePrefix(string word, char ch) {

        int index = word.find(ch);

        if (index != string::npos) {
            reverse(word.begin(), word.begin() + index + 1);
        }

        return word;
    }
};
```

---

# Time Complexity

Finding the character

```text
O(n)
```

Reversing the prefix

```text
O(n)
```

Overall

```text
O(n)
```

---

# Space Complexity

Only a few variables are used.

```text
O(1)
```

---

# Why This Works

- `find()` returns the index of the first occurrence of `ch`.
- `reverse()` reverses exactly the required prefix.
- If the character does not exist, the string remains unchanged.
- The solution is simple, efficient, and uses built-in STL functions.

---

# Functions Used

| Function | Purpose |
|----------|---------|
| `find()` | Finds the first occurrence of a character. |
| `reverse()` | Reverses the specified range of characters. |

---

# Key Takeaways

- Use `find()` to locate the first occurrence.
- Check for `string::npos` to determine whether the character exists.
- Use `reverse()` to reverse only the required prefix.
- Optimal Complexity:
  - **Time:** `O(n)`
  - **Space:** `O(1)`

---

# LeetCode Link

https://leetcode.com/problems/reverse-prefix-of-word/