# 1249. Minimum Remove to Make Valid Parentheses

## 📝 Problem Statement

Given a string `s` containing lowercase English letters and parentheses `'('` and `')'`, remove the **minimum number of parentheses** so that the resulting string is a **valid parentheses string**.

A valid parentheses string is one where:

- It is empty or contains only lowercase letters.
- It can be written as `AB`, where both `A` and `B` are valid.
- It can be written as `(A)`, where `A` is valid.

Return **any valid string** after removing the minimum number of parentheses.

**LeetCode:** https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

---

## 💡 Approach

We use a **stack** to store the indices of unmatched opening parentheses `'('`.

### Steps

1. Traverse the string from left to right.
2. If the current character is `'('`, push its index onto the stack.
3. If the current character is `')'`:
   - If the stack is **not empty**, pop one index because the brackets are matched.
   - Otherwise, mark the current `')'` as invalid.
4. After traversal, any indices remaining in the stack represent unmatched `'('`. Mark them as invalid.
5. Build the answer by skipping all marked characters.

---

## ✅ Example

### Input

```text
s = "a)b(c)d"
```

### First Pass

| Character | Action |
|-----------|--------|
| a | Keep |
| ) | No matching '(' → Mark for removal |
| b | Keep |
| ( | Push index |
| c | Keep |
| ) | Pop matching '(' |
| d | Keep |

Marked string:

```text
a*b(c)d
```

Final Answer:

```text
ab(c)d
```

---

### Input

```text
s = "lee(t(c)o)de)"
```

The last `')'` has no matching `'('`, so it is removed.

Output:

```text
lee(t(c)o)de
```

---

## ✅ C++ Solution

```cpp
class Solution {
public:
    string minRemoveToMakeValid(string s) {

        stack<int> st;

        // First pass: Remove extra ')'
        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {
                st.push(i);
            }
            else if (s[i] == ')') {

                if (!st.empty()) {
                    st.pop();
                }
                else {
                    s[i] = '*';
                }
            }
        }

        // Remove remaining '('
        while (!st.empty()) {
            s[st.top()] = '*';
            st.pop();
        }

        // Build final string
        string ans = "";

        for (char ch : s) {
            if (ch != '*') {
                ans += ch;
            }
        }

        return ans;
    }
};
```

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
  - One traversal of the string.
  - One traversal to build the answer.

- **Space Complexity:** `O(n)`
  - Stack stores indices of unmatched `'('`.
  - Additional string stores the final answer.

---

## 🔑 Key Idea

- Store the **indices** of opening brackets `'('` in a stack.
- If a closing bracket `')'` has no matching `'('`, mark it for removal.
- After the traversal, any `'('` left in the stack are also invalid and should be removed.
- Finally, construct the answer by skipping all marked characters.

---

## 📚 Topics

- Stack
- String
- Greedy
- Simulation

---

## 🚀 Takeaway

- Use a stack to keep track of unmatched opening brackets.
- Mark invalid parentheses instead of deleting them immediately.
- Build the final valid string after all invalid parentheses have been identified.