# 1207. Unique Number of Occurrences

## Problem

Given an integer array `arr`.

Return:

- `true` if every number has a **unique frequency**.
- `false` if two or more numbers have the same frequency.

---

## Example 1

Input

```text
arr = [1,2,2,1,1,3]
```

Output

```text
true
```

Explanation

```
1 → 3 times
2 → 2 times
3 → 1 time
```

All frequencies are different.

---

## Example 2

Input

```text
arr = [1,2]
```

Output

```text
false
```

Explanation

```
1 → 1 time
2 → 1 time
```

Both frequencies are the same.

---

## Example 3

Input

```text
arr = [-3,0,1,-3,1,1,1,-3,10,0]
```

Output

```text
true
```

---

# Idea

There are two tasks:

1. Count the frequency of every number.
2. Check whether any frequency appears more than once.

Use:

- `unordered_map<int,int>` → stores frequency of each number.
- `unordered_set<int>` → stores frequencies that have already appeared.

If a frequency already exists in the set, return `false`.

Otherwise insert it.

---

# Algorithm

### Step 1

Create a frequency map.

```cpp
unordered_map<int,int> freq;
```

---

### Step 2

Traverse the array.

```
freq[num]++
```

Example

```
arr = [1,2,2,1,1,3]
```

Map becomes

```
1 → 3
2 → 2
3 → 1
```

---

### Step 3

Create an empty set.

```
unordered_set<int> seen;
```

---

### Step 4

Traverse the map.

For every frequency

```
if already exists
    return false

otherwise
    insert into set
```

---

### Step 5

If every frequency is unique,

```
return true
```

---

# Dry Run

Input

```text
arr = [1,2,2,1,1,3]
```

Frequency Map

```
1 → 3
2 → 2
3 → 1
```

Set

Initially

```
{}
```

Insert

```
3
```

Set

```
{3}
```

Insert

```
2
```

Set

```
{3,2}
```

Insert

```
1
```

Set

```
{3,2,1}
```

No duplicate frequency found.

Return

```text
true
```

---

## Another Dry Run

Input

```text
arr = [1,2]
```

Frequency

```
1 → 1
2 → 1
```

Set

```
{}
```

Insert first frequency

```
{1}
```

Next frequency is also

```
1
```

Already present.

Return

```text
false
```

---

# Code

```cpp
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        unordered_map<int, int> freq;

        for (int num : arr) {
            freq[num]++;
        }

        unordered_set<int> seen;

        for (auto it : freq) {

            if (seen.count(it.second)) {
                return false;
            }

            seen.insert(it.second);
        }

        return true;
    }
};
```

---

# Complexity

Let

```
n = arr.size()
```

Time Complexity

```
O(n)
```

- Counting frequencies → `O(n)`
- Checking frequencies → `O(k)` where `k` is the number of distinct elements (`k ≤ n`)

Overall

```
O(n)
```

---

Space Complexity

```
O(n)
```

- Frequency map stores distinct numbers.
- Set stores distinct frequencies.

---

# Key Learning

- Use `unordered_map` to count frequencies.
- Use `unordered_set` to detect duplicate frequencies.
- `set.count(x)` returns:
  - `1` if `x` exists.
  - `0` otherwise.
- If a frequency repeats, immediately return `false`.

---

# Interview Tip

Whenever a problem asks:

- Count occurrences.
- Check uniqueness of frequencies.
- Detect duplicate counts.

Think of the pattern:

```
Array
   ↓
Frequency Map
   ↓
Set of Frequencies
```

This is a very common interview pattern and runs in **O(n)** time.