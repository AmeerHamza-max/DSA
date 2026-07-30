# 345. Reverse Vowels of a String

## Problem Statement

Given a string `s`, reverse **only the vowels** in the string and return the resulting string.

The vowels are:

```text
a, e, i, o, u
A, E, I, O, U
```

All non-vowel characters should remain in their original positions.

---

## Example 1

### Input

```text
s = "IceCreAm"
```

### Output

```text
"AceCreIm"
```

### Explanation

The vowels are:

```text
I, e, A
```

After reversing:

```text
A, e, I
```

Final string:

```text
AceCreIm
```

---

## Example 2

### Input

```text
s = "leetcode"
```

### Output

```text
"leotcede"
```

---

## Approach (Two Pointers)

We use two pointers:

- `left` starts from the beginning.
- `right` starts from the end.

Both pointers move toward each other.

Whenever both pointers point to vowels, we swap them.

---

## Step 1

Initialize two pointers.

```cpp
left = 0;
right = s.length() - 1;
```

---

## Step 2

Move the left pointer until it finds a vowel.

```cpp
while(left < right && !isVowel(s[left]))
    left++;
```

---

## Step 3

Move the right pointer until it finds a vowel.

```cpp
while(left < right && !isVowel(s[right]))
    right--;
```

---

## Step 4

Swap both vowels.

```cpp
swap(s[left], s[right]);
```

Move both pointers.

```cpp
left++;
right--;
```

Repeat until

```text
left >= right
```

---

# Dry Run

### Input

```text
s = "leetcode"
```

Initially

```text
l                           r
l e e t c o d e
```

Left points to

```text
e
```

Right points to

```text
e
```

Swap

```text
No visible change
```

Move pointers.

---

Now

```text
l         r
l e e t c o d e
```

Left points to

```text
e
```

Right points to

```text
o
```

Swap

```text
l o e t c e d e
```

Move pointers.

Pointers meet.

Final Answer

```text
"leotcede"
```

---

## Another Dry Run

### Input

```text
s = "hello"
```

Vowels

```text
e
o
```

Swap

```text
holle
```

Output

```text
"holle"
```

---

# Algorithm

1. Create two pointers.
2. Move the left pointer until a vowel is found.
3. Move the right pointer until a vowel is found.
4. Swap the vowels.
5. Move both pointers.
6. Repeat until both pointers meet.
7. Return the modified string.

---

# C++ Solution

```cpp
class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
               ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }

    string reverseVowels(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {

            while (left < right && !isVowel(s[left])) {
                left++;
            }

            while (left < right && !isVowel(s[right])) {
                right--;
            }

            swap(s[left], s[right]);
            left++;
            right--;
        }

        return s;
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

- The left pointer always searches for the next vowel from the beginning.
- The right pointer always searches for the next vowel from the end.
- Every pair of vowels is swapped exactly once.
- Consonants never move, so only the vowels are reversed.

---

# Key Takeaways

- Use the **Two Pointer** technique.
- Create a helper function `isVowel()` to identify vowels.
- Skip all consonants.
- Swap vowels when both pointers stop.
- This is the optimal solution with:
  - **Time Complexity:** `O(n)`
  - **Space Complexity:** `O(1)`

---

# Functions Used

| Function | Purpose |
|----------|---------|
| `isVowel()` | Checks whether a character is a vowel. |
| `swap()` | Exchanges the positions of two vowels. |

---

# LeetCode Link

https://leetcode.com/problems/reverse-vowels-of-a-string/