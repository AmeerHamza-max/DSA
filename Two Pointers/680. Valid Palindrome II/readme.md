# 680. Valid Palindrome II

## Problem Statement

Given a string `s`, return **true** if the string can become a palindrome after deleting **at most one character**.

A palindrome reads the same forward and backward.

---

## Examples

### Example 1

**Input**

```text
s = "aba"
```

**Output**

```text
true
```

The string is already a palindrome.

---

### Example 2

**Input**

```text
s = "abca"
```

**Output**

```text
true
```

Delete `'c'` and we get:

```text
"aba"
```

which is a palindrome.

---

### Example 3

**Input**

```text
s = "abc"
```

**Output**

```text
false
```

Removing either `'a'`, `'b'`, or `'c'` does not produce a palindrome.

---

## Approach (Two Pointers)

Use two pointers:

* `left` starts from the beginning.
* `right` starts from the end.

Move both pointers toward the center.

### If characters match

Continue moving.

### If characters do not match

We are allowed to delete **one** character.

At the first mismatch, try **both possibilities**:

1. Delete the left character.
2. Delete the right character.

If **either** remaining substring is a palindrome, return `true`.

---

## Why Only One Mismatch Matters

The problem allows deleting **at most one character**.

As soon as we encounter the first mismatch, we must use our single deletion there.

If neither deletion works, the answer is `false`.

---

## Helper Function

We create a function:

```cpp
checkPalindrome(s, left, right)
```

It checks whether the substring from `left` to `right` is a palindrome.

---

## Dry Run

### Input

```text
s = "abca"
```

Initial pointers:

```text
left = 0 ('a')
right = 3 ('a')
```

They match.

Move inward:

```text
left = 1 ('b')
right = 2 ('c')
```

Mismatch found.

### Option 1: Delete `'b'`

Check substring:

```text
"ca"
```

Not a palindrome.

### Option 2: Delete `'c'`

Check substring:

```text
"ba"
```

Wait — the correct remaining string is obtained by skipping `'c'` in the original comparison, leaving:

```text
"aba"
```

which is a palindrome.

Return:

```text
true
```

---

## Another Dry Run

### Input

```text
s = "abc"
```

Compare:

```text
a != c
```

Try deleting `'a'`:

```text
"bc"
```

Not a palindrome.

Try deleting `'c'`:

```text
"ab"
```

Not a palindrome.

Return:

```text
false
```

---

## Algorithm

1. Initialize `left = 0` and `right = n - 1`.
2. While `left < right`:

   * If characters are equal, move both pointers.
   * Otherwise:

     * Check if `s[left+1 ... right]` is a palindrome.
     * Check if `s[left ... right-1]` is a palindrome.
     * Return `true` if either is valid.
3. If the loop finishes, return `true`.

---

## C++ Solution

```cpp
class Solution {
public:

    bool checkPalindrome(string &s, int left, int right){

        while(left < right){

            if(s[left] != s[right]){
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    bool validPalindrome(string s) {

        int left = 0;
        int right = s.length() - 1;

        while(left < right){

            if(s[left] != s[right]){

                return checkPalindrome(s, left + 1, right) ||
                       checkPalindrome(s, left, right - 1);
            }

            left++;
            right--;
        }

        return true;
    }
};
```

---

## Time Complexity

* The main two-pointer scan is **O(n)**.
* The helper palindrome check is also **O(n)**.
* It is called at most **two times**.

Overall:

```text
O(n)
```

---

## Space Complexity

Only a few variables are used.

```text
O(1)
```

---

## Why This Works

* A palindrome must match from both ends.
* The first mismatch is the **only place** where a deletion can help.
* We test both possible deletions.
* If one remaining substring is a palindrome, the original string can become a palindrome after deleting one character.

---

## Key Takeaways

* Use the **two-pointer technique**.
* At the first mismatch, try **skipping the left** or **skipping the right** character.
* Use a helper function to verify the remaining substring.
* Optimal complexity:

  * **Time:** `O(n)`
  * **Space:** `O(1)`

---

## LeetCode Link

https://leetcode.com/problems/valid-palindrome-ii/
