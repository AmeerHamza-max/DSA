# Reverse Vowels of a String (LeetCode 345)

## Problem Statement

Given a string `s`, reverse **only the vowels** in the string and return the modified string.

The vowels are:

- `a`
- `e`
- `i`
- `o`
- `u`

Vowels can appear in both **lowercase** and **uppercase** letters.

---

## Examples

### Example 1

**Input**

```text
s = "IceCreAm"
```

**Output**

```text
AceCreIm
```

**Explanation**

Original vowels:

```text
I, e, e, A
```

After reversing:

```text
A, e, e, I
```

Final string:

```text
AceCreIm
```

---

### Example 2

**Input**

```text
s = "leetcode"
```

**Output**

```text
leotcede
```

---

## Approach

This problem can be solved efficiently using the **Two Pointer** technique.

### Step 1

Create two pointers:

- `left` starting from the beginning of the string.
- `right` starting from the end of the string.

```text
IceCreAm

^      ^
left  right
```

---

### Step 2

Move the `left` pointer forward until it points to a vowel.

```text
I c e C r e A m
^
```

If the current character is not a vowel, continue moving forward.

---

### Step 3

Move the `right` pointer backward until it points to a vowel.

```text
I c e C r e A m
              ^
```

If the current character is not a vowel, continue moving backward.

---

### Step 4

Once both pointers point to vowels, swap them.

Before swapping:

```text
I c e C r e A m
^           ^
```

After swapping:

```text
A c e C r e I m
```

---

### Step 5

Move both pointers.

```cpp
left++;
right--;
```

Repeat the process until:

```cpp
left >= right
```

---

## Algorithm

1. Initialize two pointers:
   - `left = 0`
   - `right = s.length() - 1`
2. Create a helper function `isVowel()` to check whether a character is a vowel.
3. Move the `left` pointer until a vowel is found.
4. Move the `right` pointer until a vowel is found.
5. Swap the vowels.
6. Move both pointers inward.
7. Repeat until both pointers cross.
8. Return the modified string.

---

## Dry Run

### Input

```text
IceCreAm
```

Initial state:

```text
I c e C r e A m
^             ^
```

Both pointers are on vowels.

Swap:

```text
A c e C r e I m
```

Move pointers:

```text
    ^       ^
```

Both pointers now point to `e`.

Swap:

```text
A c e C r e I m
```

Pointers cross.

Final Answer:

```text
AceCreIm
```

---

## C++ Solution

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

## Time Complexity

| Operation | Complexity |
|-----------|------------|
| Traversing the string | **O(n)** |

Each character is visited at most once by either the `left` or `right` pointer.

**Overall Time Complexity**

```text
O(n)
```

---

## Space Complexity

No extra data structure is used.

```text
O(1)
```

---

## Key Concepts Used

- Two Pointers
- String Manipulation
- Helper Function
- Character Comparison
- In-place Swapping

---

## Why Two Pointers?

Using two pointers allows us to process the string from both ends simultaneously.

Instead of storing vowels in another array and reversing them later, we directly swap vowels in the original string, making the solution more efficient.

---

## Edge Cases

- String with no vowels

```text
Input: "bcdfg"

Output: "bcdfg"
```

---

- String with only vowels

```text
Input: "aeiou"

Output: "uoiea"
```

---

- Single character

```text
Input: "a"

Output: "a"
```

---

- Uppercase vowels

```text
Input: "AEIOU"

Output: "UOIEA"
```

---

## Learning Outcome

After solving this problem, you will learn:

- How to use the Two Pointer technique effectively.
- How to traverse a string from both ends.
- How to write helper functions for cleaner code.
- How to perform in-place modifications without extra memory.
- How to solve string manipulation problems efficiently in linear time.

---

## Tags

- LeetCode 345
- Easy
- Two Pointers
- String
- Character Manipulation
```