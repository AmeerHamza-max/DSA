# 2418. Sort the People

## Problem

You are given two arrays:

- `names`
- `heights`

Both arrays have the same length.

- `names[i]` represents the name of a person.
- `heights[i]` represents the height of that person.

Return the names sorted in **descending order of height**.

---

## Example 1

Input

```text
names = ["Mary","John","Emma"]
heights = [180,165,170]
```

Output

```text
["Mary","Emma","John"]
```

Explanation

```
180 → Mary
170 → Emma
165 → John
```

---

## Example 2

Input

```text
names = ["Alice","Bob","Bob"]
heights = [155,185,150]
```

Output

```text
["Bob","Alice","Bob"]
```

---

# Idea

The `names` and `heights` arrays are connected by their indices.

Create pairs:

```
(height, name)
```

Example

```
(180, Mary)
(165, John)
(170, Emma)
```

Now sort these pairs in **descending order of height**.

Finally, collect only the names.

---

# Algorithm

### Step 1

Create a vector of pairs.

```cpp
vector<pair<int,string>> people;
```

---

### Step 2

Store every person.

Example

```
people

↓

(180, Mary)
(165, John)
(170, Emma)
```

---

### Step 3

Sort in descending order.

```cpp
sort(people.begin(), people.end(), greater<pair<int,string>>());
```

Result

```
(180, Mary)
(170, Emma)
(165, John)
```

---

### Step 4

Traverse the sorted vector.

Take only the names.

```
Mary
Emma
John
```

Return the answer.

---

# Dry Run

Input

```text
names = ["Mary","John","Emma"]

heights = [180,165,170]
```

Create pairs

```
(180, Mary)

(165, John)

(170, Emma)
```

Sort

```
(180, Mary)

(170, Emma)

(165, John)
```

Collect names

```
Mary

Emma

John
```

Return

```text
["Mary","Emma","John"]
```

---

# Code

```cpp
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {

        vector<pair<int, string>> people;

        for (int i = 0; i < names.size(); i++) {
            people.push_back({heights[i], names[i]});
        }

        sort(people.begin(), people.end(), greater<pair<int, string>>());

        vector<string> ans;

        for (auto person : people) {
            ans.push_back(person.second);
        }

        return ans;
    }
};
```

---

# Complexity

Let

```
n = names.size()
```

Time Complexity

Creating pairs

```
O(n)
```

Sorting

```
O(n log n)
```

Collecting names

```
O(n)
```

Overall

```
O(n log n)
```

---

Space Complexity

We store all pairs.

```
O(n)
```

---

# Key Learning

- When two arrays are related by index, combine them into **pairs**.
- `pair<height, name>` keeps the relationship intact.
- Sorting pairs automatically sorts by the first element (`height`).
- `greater<pair<int,string>>()` sorts the pairs in descending order.

---

# Interview Tip

Whenever you have:

```
Array A

Array B
```

and both are connected by the same index, think of this pattern:

```
(A[i], B[i])
      ↓
Store as pair
      ↓
Sort
      ↓
Extract required values
```

This is a very common technique for sorting one array based on another related array.