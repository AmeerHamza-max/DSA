# 1370. Increasing Decreasing String

## Problem

Given a string `s`, reorder it using the following rules:

1. Pick characters from **smallest to largest**.
2. Then pick characters from **largest to smallest**.
3. Repeat until every character has been used.

Return the final reordered string.

---

## Example 1

Input

```text
s = "aaaabbbbcccc"
```

Output

```text
abccbaabccba
```

Explanation

Round 1

```
a → b → c
```

Result

```
abc
```

Now reverse

```
c → b → a
```

Result

```
abccba
```

Repeat with remaining letters

Final

```
abccbaabccba
```

---

## Example 2

Input

```text
s = "rat"
```

Output

```text
art
```

---

# Idea

Since the string contains only lowercase English letters, we only need a frequency array of size **26**.

First count how many times each letter appears.

Then repeat:

- Traverse from `a` to `z`.
  - If a letter is available, append it once and decrease its count.
- Traverse from `z` to `a`.
  - If a letter is available, append it once and decrease its count.

Continue until the answer length becomes equal to the original string length.

---

# Algorithm

1. Create a frequency array of size 26.
2. Count every character.
3. While answer is incomplete:
   - Traverse from `a` to `z`.
   - Append available letters.
   - Traverse from `z` to `a`.
   - Append available letters.
4. Return the answer.

---

# Dry Run

Input

```text
s = "aaaabbbbcccc"
```

Frequency

```
a = 4
b = 4
c = 4
```

---

### Round 1 (Increasing)

Take

```
a
b
c
```

Remaining

```
a = 3
b = 3
c = 3
```

Answer

```
abc
```

---

### Round 1 (Decreasing)

Take

```
c
b
a
```

Remaining

```
a = 2
b = 2
c = 2
```

Answer

```
abccba
```

---

### Round 2

Increasing

```
abc
```

Answer

```
abccbaabc
```

Decreasing

```
cba
```

Final

```
abccbaabccba
```

---

# Code

```cpp
class Solution {
public:
    string sortString(string s) {

        vector<int> freq(26, 0);

        for(char ch : s){
            freq[ch - 'a']++;
        }

        string ans = "";

        while(ans.length() < s.length()){

            for(int i = 0; i < 26; i++){
                if(freq[i] > 0){
                    ans += char(i + 'a');
                    freq[i]--;
                }
            }

            for(int i = 25; i >= 0; i--){
                if(freq[i] > 0){
                    ans += char(i + 'a');
                    freq[i]--;
                }
            }
        }

        return ans;
    }
};
```

---

# Complexity

Let

```
n = s.length()
```

Time Complexity

Each character is added exactly once.

```
O(n + 26 × rounds)
```

Since 26 is constant, this simplifies to

```
O(n)
```

Space Complexity

Frequency array

```
O(26)
```

which is

```
O(1)
```

---

# Key Learning

- A frequency array is very useful when characters are limited (`a`–`z`).
- We don't need to sort the string explicitly.
- Alternate between:
  - Increasing order (`a → z`)
  - Decreasing order (`z → a`)
- Decrease the frequency every time a character is used.

---

# Interview Tip

When a problem says:

- lowercase English letters only
- repeatedly pick smallest/largest character

Think about using a **26-size frequency array** instead of sorting repeatedly. It is simpler, faster, and uses constant extra space.