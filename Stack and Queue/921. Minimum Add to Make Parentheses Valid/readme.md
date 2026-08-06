# 921. Minimum Add to Make Parentheses Valid

## 📝 Problem Statement

A parentheses string is valid if:

- It is an empty string.
- It can be written as `AB`, where both `A` and `B` are valid.
- It can be written as `(A)`, where `A` is a valid parentheses string.

Given a string `s` containing only `'('` and `')'`, return the **minimum number of parentheses** that must be inserted to make the string valid.

**LeetCode:** https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

---

## 💡 Approach

We use two variables:

- **open** → Counts unmatched opening parentheses `'('`.
- **moves** → Counts the minimum insertions required.

### Algorithm

1. Traverse the string from left to right.
2. If the current character is `'('`, increment `open`.
3. If the current character is `')'`:
   - If there is an unmatched `'('`, decrement `open`.
   - Otherwise, increment `moves` because we need to insert an opening parenthesis.
4. After traversal, any remaining unmatched `'('` also require closing parentheses.
5. Add `open` to `moves`.
6. Return `moves`.

---

## ✅ Example

### Input

```text
s = "())"
```

### Dry Run

| Character | Open | Moves |
|-----------|-----:|------:|
| ( | 1 | 0 |
| ) | 0 | 0 |
| ) | 0 | 1 |

Remaining `open = 0`

Answer = **1**

---

### Input

```text
s = "((("
```

Remaining:

```text
open = 3
moves = 0
```

Answer:

```text
moves = moves + open = 3
```

---

## ✅ C++ Solution

```cpp
class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int moves = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                open++;
            } else {
                if (open > 0) {
                    open--;
                } else {
                    moves++;
                }
            }
        }

        moves += open;
        return moves;
    }
};
```

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 🎯 Key Idea

- `open` stores the number of unmatched opening parentheses.
- Every unmatched `')'` requires inserting one `'('`.
- Every unmatched `'('` at the end requires inserting one `')'`.

This greedy approach solves the problem in a **single traversal** using **constant extra space**.

---

## 📚 Topics

- String
- Greedy
- Parentheses
- Simulation