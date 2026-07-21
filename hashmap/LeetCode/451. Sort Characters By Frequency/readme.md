# 451. Sort Characters By Frequency

## Problem

Given a string `s`.

Sort the characters in **decreasing order of frequency**.

If two characters have the same frequency, any order is acceptable.

---

## Example 1

Input

```text
s = "tree"
```

Output

```text
"eert"
```

Explanation

```
e → 2 times
t → 1 time
r → 1 time
```

So `e` must come first.

Possible answers

```
eert
eetr
```

---

## Example 2

Input

```text
s = "cccaaa"
```

Output

```text
cccaaa
```

or

```text
aaaccc
```

Both are correct because both characters appear 3 times.

---

## Example 3

Input

```text
s = "Aabb"
```

Output

```text
bbAa
```

Explanation

Uppercase and lowercase are different.

```
A ≠ a
```

---

# Idea

We need two things:

1. Count frequency of every character.
2. Sort characters according to frequency.

Use

```
unordered_map<char,int>
```

to count frequencies.

Then store

```
(character, frequency)
```

inside a vector.

Finally sort the vector according to frequency.

---

# Algorithm

### Step 1

Count frequencies.

Example

```
tree
```

Map

```
t → 1
r → 1
e → 2
```

---

### Step 2

Store inside vector.

```
[
(t,1),
(r,1),
(e,2)
]
```

---

### Step 3

Sort in descending order.

```
[
(e,2),
(t,1),
(r,1)
]
```

---

### Step 4

Append each character frequency times.

```
ee
+
t
+
r
=
eetr
```

Return answer.

---

# Dry Run

Input

```text
s = "tree"
```

Frequency

```
t → 1
r → 1
e → 2
```

Sorted

```
e → 2
t → 1
r → 1
```

Answer

```
ee
+
t
+
r
=
eetr
```

Another valid answer

```
eert
```

---

# Code

```cpp
class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> freq;

        for (char ch : s) {
            freq[ch]++;
        }

        vector<pair<char, int>> arr;

        for (auto it : freq) {
            arr.push_back({it.first, it.second});
        }

        sort(arr.begin(), arr.end(),
             [](pair<char, int>& a, pair<char, int>& b) {
                 return a.second > b.second;
             });

        string ans = "";

        for (auto it : arr) {
            ans.append(it.second, it.first);
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
k = number of distinct characters
```

Time Complexity

```
Counting frequency : O(n)

Sorting            : O(k log k)

Building answer    : O(n)
```

Overall

```
O(n + k log k)
```

Since `k` is at most the number of distinct characters, this is efficient.

---

Space Complexity

```
O(k)
```

for the map and vector.

---

# Key Learning

- `unordered_map` is useful for counting frequencies.
- Store `(character, frequency)` pairs in a vector when you need to sort by frequency.
- Use a custom comparator with `sort()`.
- `string::append(count, ch)` appends the same character multiple times.

Example

```cpp
ans.append(3, 'a');
```

Result

```
aaa
```

---

# Interview Tip

Whenever a problem says:

- Count frequency.
- Sort according to frequency.
- Return elements grouped by occurrence.

Think of this pattern:

```
Input
   ↓
Frequency Map
   ↓
Vector of Pairs
   ↓
Sort
   ↓
Build Answer
```

This is one of the most common patterns for frequency-based string and array problems.