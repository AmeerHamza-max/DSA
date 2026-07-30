# 125. Valid Palindrome

## Problem Statement

A phrase is a **palindrome** if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward.

Given a string `s`, return:

- `true` if it is a palindrome.
- `false` otherwise.

---

## Example 1

### Input

```text
s = "A man, a plan, a canal: Panama"
```

### Output

```text
true
```

### Explanation

After removing non-alphanumeric characters and converting to lowercase:

```text
"amanaplanacanalpanama"
```

It reads the same from both directions.

---

## Example 2

### Input

```text
s = "race a car"
```

### Output

```text
false
```

---

## Example 3

### Input

```text
s = " "
```

### Output

```text
true
```

### Explanation

After removing non-alphanumeric characters, the string becomes empty, which is considered a palindrome.

---

# Approach (Two Pointers)

We use **two pointers**:

- `left` starts from the beginning.
- `right` starts from the end.

Both pointers move toward each other.

---

## Step 1

Initialize two pointers.

```cpp
left = 0;
right = s.length() - 1;
```

---

## Step 2

Ignore all non-alphanumeric characters.

Example:

```text
A man, a plan, a canal: Panama
```

Characters like

```text
' '
','
':'
```

are skipped.

---

## Step 3

Convert both characters to lowercase before comparing.

```cpp
tolower(s[left])
tolower(s[right])
```

This makes

```text
'A' == 'a'
```

---

## Step 4

If both characters are different,

return

```text
false
```

Otherwise move both pointers.

```cpp
left++;
right--;
```

Continue until

```text
left >= right
```

If no mismatch is found,

return

```text
true
```

---

# Dry Run

### Input

```text
"A man, a plan, a canal: Panama"
```

Initially

```text
left -> A
right -> a
```

Compare

```text
a == a
```

Move both pointers.

---

Skip spaces and punctuation.

```text
left -> m
right -> m
```

Compare

```text
m == m
```

Move again.

---

Continue comparing every valid character.

No mismatch is found.

Answer

```text
true
```

---

### Another Example

Input

```text
"race a car"
```

Compare

```text
r == r
```

Move pointers.

Compare

```text
a == a
```

Move pointers.

Compare

```text
c != e
```

Mismatch found.

Return

```text
false
```

---

# Algorithm

1. Initialize `left` at the beginning.
2. Initialize `right` at the end.
3. Skip non-alphanumeric characters from both sides.
4. Convert both characters to lowercase.
5. Compare them.
6. If they are different, return `false`.
7. Move both pointers.
8. Repeat until pointers meet.
9. Return `true`.

---

# C++ Solution

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {

            // Skip non-alphanumeric characters from the left
            while (left < right && !isalnum(s[left])) {
                left++;
            }

            // Skip non-alphanumeric characters from the right
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            // Compare characters (case-insensitive)
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
```

---

# Time Complexity

Each character is visited at most once.

```text
O(n)
```

---

# Space Complexity

Only two pointers are used.

```text
O(1)
```

---

# Why This Works

- Non-alphanumeric characters are ignored.
- `tolower()` makes the comparison case-insensitive.
- Two pointers compare characters from both ends simultaneously.
- The algorithm stops immediately when a mismatch is found.

---

# Key Takeaways

- Use **two pointers** for efficient comparison.
- Skip characters using `isalnum()`.
- Compare characters using `tolower()`.
- No extra string is required.
- Optimal solution:
  - **Time Complexity:** `O(n)`
  - **Space Complexity:** `O(1)`

---

# Functions Used

| Function | Purpose |
|----------|---------|
| `isalnum()` | Checks whether a character is a letter or digit. |
| `tolower()` | Converts an uppercase letter to lowercase. |

---

# LeetCode Link

https://leetcode.com/problems/valid-palindrome/