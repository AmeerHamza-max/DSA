# 20. Valid Parentheses

## Problem Statement

Given a string `s` containing only the characters:

- `(`
- `)`
- `{`
- `}`
- `[`
- `]`

Determine whether the input string is **valid**.

A string is valid if:

1. Every opening bracket has a corresponding closing bracket of the same type.
2. Brackets are closed in the correct order.
3. Every closing bracket has a matching opening bracket.

---

## Examples

### Example 1

**Input**

```text
s = "()"
```

**Output**

```text
true
```

---

### Example 2

**Input**

```text
s = "()[]{}"
```

**Output**

```text
true
```

---

### Example 3

**Input**

```text
s = "(]"
```

**Output**

```text
false
```

---

### Example 4

**Input**

```text
s = "([])"
```

**Output**

```text
true
```

---

### Example 5

**Input**

```text
s = "([)]"
```

**Output**

```text
false
```

---

# Approach

This problem can be solved using a **stack**.

- Traverse the string from left to right.
- If the current character is an opening bracket (`(`, `{`, `[`), push it into the stack.
- If the current character is a closing bracket:
  - If the stack is empty, return `false`.
  - Otherwise, compare it with the top element of the stack.
  - If both brackets match, remove the top element.
  - Otherwise, return `false`.
- After traversing the entire string:
  - If the stack is empty, return `true`.
  - Otherwise, return `false`.

---

# Algorithm

1. Create an empty stack (or `vector<char>`).
2. Traverse the string.
3. Push every opening bracket.
4. For every closing bracket:
   - If the stack is empty, return `false`.
   - If the top bracket matches, pop it.
   - Otherwise, return `false`.
5. Return `true` if the stack is empty; otherwise return `false`.

---

# Code

```cpp
class Solution {
public:
    bool isValid(string s) {
        vector<char> arr;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                arr.push_back(s[i]);
            }
            else {
                if (arr.empty()) {
                    return false;
                }

                else if ((s[i] == ')' && arr.back() == '(') ||
                         (s[i] == '}' && arr.back() == '{') ||
                         (s[i] == ']' && arr.back() == '[')) {
                    arr.pop_back();
                }

                else {
                    return false;
                }
            }
        }

        return arr.empty();
    }
};
```

---

# Complexity Analysis

- **Time Complexity:** `O(n)`
  - Each character is processed only once.

- **Space Complexity:** `O(n)`
  - In the worst case, all opening brackets are stored in the stack.

---

# Key Learning

- Learned how to use a **stack** (implemented with `vector<char>`).
- Understood the **LIFO (Last In, First Out)** concept.
- Practiced matching opening and closing brackets.
- Learned to check for stack underflow using `empty()`.
- Learned how `push_back()`, `back()`, and `pop_back()` work together.
- Learned why `return arr.empty();` determines the final answer.

---

## LeetCode

**Problem:** 20. Valid Parentheses

**Difficulty:** Easy

**Topics:** Stack, String