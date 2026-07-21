# Valid Palindrome (LeetCode 125)

## Problem Statement

A phrase is considered a **palindrome** if, after:

- Converting all uppercase letters to lowercase.
- Removing all non-alphanumeric characters.

it reads the same forward and backward.

Alphanumeric characters include:

- Letters (`a-z`, `A-Z`)
- Digits (`0-9`)

Return `true` if the given string is a palindrome; otherwise, return `false`.

---

## Examples

### Example 1

**Input**

```text
s = "A man, a plan, a canal: Panama"
```

**Output**

```text
true
```

**Explanation**

After removing spaces, commas, and the colon, and converting to lowercase:

```text
amanaplanacanalpanama
```

Reading from left to right and right to left gives the same result.

---

### Example 2

**Input**

```text
s = "race a car"
```

**Output**

```text
false
```

**Explanation**

After preprocessing:

```text
raceacar
```

Forward:

```text
raceacar
```

Backward:

```text
racaecar
```

Both are different, so the string is **not** a palindrome.

---

### Example 3

**Input**

```text
s = " "
```

**Output**

```text
true
```

**Explanation**

After removing all non-alphanumeric characters, the string becomes empty.

An empty string is considered a palindrome.

---

# Approach

This problem is efficiently solved using the **Two Pointer** technique.

Instead of creating a new string, we compare characters directly from both ends while ignoring unwanted characters.

---

## Step 1

Initialize two pointers.

```cpp
left = 0;
right = s.length() - 1;
```

---

## Step 2

Move the `left` pointer until it reaches an alphanumeric character.

Ignore:

- Spaces
- Commas
- Colons
- Periods
- Special characters

Example:

```text
A man
 ^
```

Space is ignored.

Move to:

```text
A man
  ^
```

---

## Step 3

Move the `right` pointer backward until it reaches an alphanumeric character.

Example:

```text
Panama:
      ^
```

Colon is ignored.

Move left until a letter or digit is found.

---

## Step 4

Convert both characters to lowercase using:

```cpp
tolower(character)
```

This makes the comparison case-insensitive.

Example:

```text
'A' → 'a'
'P' → 'p'
```

---

## Step 5

Compare both characters.

If they are different:

```cpp
return false;
```

Otherwise:

```cpp
left++;
right--;
```

Continue until both pointers meet or cross.

---

## Algorithm

1. Initialize `left` and `right`.
2. Skip all non-alphanumeric characters from the left.
3. Skip all non-alphanumeric characters from the right.
4. Convert both characters to lowercase.
5. Compare both characters.
6. If they are different, return `false`.
7. Move both pointers inward.
8. Repeat until `left >= right`.
9. Return `true`.

---

# Dry Run

### Input

```text
A man, a plan, a canal: Panama
```

Initial:

```text
A m a n ,   a   p l a n ,   a   c a n a l :   P a n a m a
^                                                       ^
```

Compare:

```text
A == a
```

After lowercase:

```text
a == a
```

Move pointers.

Skip spaces and punctuation.

Compare:

```text
m == m
```

Move pointers.

Compare:

```text
a == a
```

Continue the same process.

Finally:

```text
amanaplanacanalpanama
```

Forward and backward are identical.

Return:

```text
true
```

---

# C++ Solution

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {

            while (left < right && !isalnum(s[left])) {
                left++;
            }

            while (left < right && !isalnum(s[right])) {
                right--;
            }

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

| Operation | Complexity |
|----------|------------|
| Traversing the string | **O(n)** |

Each character is visited at most once.

**Overall Time Complexity**

```text
O(n)
```

---

# Space Complexity

No additional string or data structure is used.

```text
O(1)
```

---

# Why Two Pointers?

Using two pointers allows us to compare characters from both ends of the string without creating a new filtered string.

Benefits:

- Efficient
- Constant extra space
- Single traversal
- Easy to implement

---

# Edge Cases

### Empty String

```text
Input: ""
Output: true
```

---

### String with Only Spaces

```text
Input: "   "
Output: true
```

---

### String with Only Special Characters

```text
Input: "@#$%^"
Output: true
```

After removing non-alphanumeric characters, the string becomes empty.

---

### Mixed Uppercase and Lowercase

```text
Input: "MadAm"
Output: true
```

---

### Numbers

```text
Input: "12321"
Output: true
```

---

### Letters and Numbers

```text
Input: "1b1"
Output: true
```

---

### Not a Palindrome

```text
Input: "hello"
Output: false
```

---

# Key Concepts Used

- Two Pointers
- String Traversal
- Character Comparison
- Case Conversion
- Alphanumeric Checking
- In-place Processing

---

# Functions Used

| Function | Purpose |
|----------|---------|
| `isalnum()` | Checks whether a character is a letter or digit |
| `tolower()` | Converts an uppercase character to lowercase |
| `string.length()` | Returns the length of the string |

---

# Learning Outcome

After solving this problem, you will learn:

- How to use the Two Pointer technique for string problems.
- How to ignore unwanted characters during traversal.
- How to perform case-insensitive comparisons.
- How to solve palindrome problems efficiently without creating an extra string.
- How to use the C++ standard library functions `isalnum()` and `tolower()` effectively.

---

# Tags

- LeetCode 125
- Easy
- Two Pointers
- String
- Character Manipulation
- Palindrome
- C++