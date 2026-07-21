# 💎 Jewels and Stones (Brute Force Solution)

## Problem Statement

You are given two strings:

* **`jewels`**: Represents the types of stones that are considered jewels.
* **`stones`**: Represents the stones you have.

Return the number of stones that are also jewels.

### Example

**Input**

```text
jewels = "aA"
stones = "aAAbbbb"
```

**Output**

```text
3
```

**Explanation**

The stones `'a'`, `'A'`, and `'A'` are jewels, so the answer is **3**.

---

# Approach

This solution uses a **Brute Force** approach.

For every character in the `jewels` string:

1. Traverse the entire `stones` string.
2. Compare the current jewel with every stone.
3. If they are equal, increment the count.
4. Return the final count after all comparisons.

---

# Algorithm

1. Initialize `count = 0`.
2. Loop through every character in `jewels`.
3. For each jewel, loop through every character in `stones`.
4. If both characters match, increment `count`.
5. Return `count`.

---

# C++ Solution

```cpp
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;

        for(int i = 0; i < jewels.size(); i++) {
            for(int j = 0; j < stones.size(); j++) {
                if(jewels[i] == stones[j]) {
                    count++;
                }
            }
        }

        return count;
    }
};
```

---

# Dry Run

### Input

```text
jewels = "aA"
stones = "aAAbbbb"
```

### Iteration

#### Jewel = 'a'

Compare with every stone:

```text
a == a ✅
a == A ❌
a == A ❌
a == b ❌
a == b ❌
a == b ❌
a == b ❌
```

Count = **1**

---

#### Jewel = 'A'

Compare with every stone:

```text
A == a ❌
A == A ✅
A == A ✅
A == b ❌
A == b ❌
A == b ❌
A == b ❌
```

Count = **3**

---

### Final Answer

```text
3
```

---

# Time Complexity

Let:

* **n = jewels.length()**
* **m = stones.length()**

The algorithm compares every jewel with every stone.

**Time Complexity**

```text
O(n × m)
```

---

# Space Complexity

No extra data structure is used.

```text
O(1)
```

---

# Advantages

* Very easy to understand.
* Simple implementation.
* No extra memory required.

---

# Disadvantages

* Inefficient for large inputs.
* Performs many unnecessary comparisons.
* There is a more efficient solution using a Hash Set.

---

# Optimized Approach

An optimized solution uses an `unordered_set`:

1. Store all jewel characters in a hash set.
2. Traverse the `stones` string once.
3. If a stone exists in the set, increment the count.

This reduces the time complexity to:

```text
Time Complexity: O(n + m)
Space Complexity: O(n)
```

---

# Learning Outcomes

After solving this problem, you will understand:

* Nested loops
* Brute Force approach
* String traversal in C++
* Character comparison
* Time and Space Complexity analysis
* Why Hashing can optimize search problems

---

# Author

**Ameer Hamza**

Data Structures & Algorithms (DSA) Practice | LeetCode Solutions
