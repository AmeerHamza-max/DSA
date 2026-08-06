# 1047. Remove All Adjacent Duplicates In String

## Problem

Given a string `s`, repeatedly remove adjacent duplicate characters until no adjacent duplicates remain.

Return the final string after all possible removals.

---

## Approach

We use a **stack** (implemented using a `vector<char>`).

### Steps

1. Traverse the string from left to right.
2. If the stack is empty, push the current character.
3. Otherwise:
   - If the current character is the same as the top of the stack, remove the top element (`pop_back()`).
   - Otherwise, push the current character into the stack.
4. After processing all characters, convert the stack into a string and return it.

---

## Dry Run

### Input

```text
s = "abbaca"
```

| Current Character | Stack | Action |
|-------------------|-------|--------|
| a | a | Push |
| b | ab | Push |
| b | a | Pop duplicate |
| a | Empty | Pop duplicate |
| c | c | Push |
| a | ca | Push |

### Output

```text
"ca"
```

---

## Example 2

### Input

```text
s = "azxxzy"
```

| Current Character | Stack | Action |
|-------------------|-------|--------|
| a | a | Push |
| z | az | Push |
| x | azx | Push |
| x | az | Pop duplicate |
| z | a | Pop duplicate |
| y | ay | Push |

### Output

```text
"ay"
```

---

## Why Stack?

The stack always keeps the current valid string.

- If the current character matches the top of the stack, both are adjacent duplicates, so we remove the top.
- Otherwise, we add the current character.

This naturally handles chain reactions after removals.

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
    string removeDuplicates(string s) {
        vector<char> ch;

        for (int i = 0; i < s.length(); i++) {
            if (ch.empty()) {
                ch.push_back(s[i]);
            }
            else if (ch.back() == s[i]) {
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

- This problem is a classic **Stack** problem.
- A `vector<char>` can be used as a stack using:
  - `push_back()`
  - `pop_back()`
  - `back()`
- Every character is pushed and popped at most once, making the solution efficient.
- Removing duplicates immediately ensures that new adjacent duplicates formed after removal are also handled automatically.

---

## Topics

- Stack
- String
- Simulation
```