# 1544. Make The String Great

## Problem

Given a string `s` containing lowercase and uppercase English letters, remove adjacent characters if they are the same letter but in different cases (one uppercase and one lowercase).

Keep removing such pairs until no more bad adjacent pairs remain.

Return the final good string.

---

## Approach

We use a **stack** (implemented using a `vector<char>`).

### Steps

1. Traverse each character in the string.
2. If the stack is empty, push the character.
3. Otherwise, compare the current character with the top of the stack.
4. If the ASCII difference between them is **32**, they are the same letter in different cases.
   - Pop the top element.
5. Otherwise, push the current character.
6. Convert the stack into a string and return it.

---

## Why `abs(ch.back() - s[i]) == 32`?

In ASCII:

| Character | ASCII |
|-----------|------:|
| A | 65 |
| a | 97 |
| B | 66 |
| b | 98 |
| Z | 90 |
| z | 122 |

The difference between an uppercase and lowercase version of the same letter is always **32**.

Example:

```text
'a' - 'A' = 32
'b' - 'B' = 32
```

So,

```cpp
abs(ch.back() - s[i]) == 32
```

means both characters are the same alphabet with different cases.

---

## Dry Run

### Input

```text
s = "leEeetcode"
```

| Current Character | Stack | Action |
|-------------------|-------|--------|
| l | l | Push |
| e | le | Push |
| E | l | Pop (`e` and `E`) |
| e | le | Push |
| e | lee | Push |
| t | leet | Push |
| c | leetc | Push |
| o | leetco | Push |
| d | leetcod | Push |
| e | leetcode | Push |

### Output

```text
leetcode
```

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

where `n` is the length of the string.

---

## C++ Solution

```cpp
class Solution {
public:
    string makeGood(string s) {
        vector<char> ch;

        for (int i = 0; i < s.length(); i++) {
            if (ch.empty()) {
                ch.push_back(s[i]);
            }
            else if (abs(ch.back() - s[i]) == 32) {
                ch.pop_back();
            }
            else {
                ch.push_back(s[i]);
            }
        }

        string str(ch.begin(), ch.end());
        return str;
    }
};
```

---

## Key Takeaways

- This problem is a classic **Stack** application.
- A `vector<char>` can be used as a stack using `push_back()`, `pop_back()`, and `back()`.
- The ASCII difference between uppercase and lowercase letters is **32**, which makes comparison simple.
- Every character is pushed and popped at most once, giving an efficient `O(n)` solution.

---

## Topics

- Stack
- String
- Simulation
- ASCII