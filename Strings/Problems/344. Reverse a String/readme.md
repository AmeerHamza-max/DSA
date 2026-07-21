# 🔄 Reverse String Using Two Pointers (C++)

## Overview

This program reverses a string stored in a `vector<char>` using the **Two Pointer** technique.

Instead of creating a new vector, the algorithm swaps characters from both ends of the vector until they meet in the middle. This makes the solution efficient in both time and space.

---

# Problem Statement

Given a vector of characters, reverse the characters **in-place**.

### Example

**Input**

```text
['h', 'e', 'l', 'l', 'o']
```

**Output**

```text
['o', 'l', 'l', 'e', 'h']
```

---

# Approach

The solution uses the **Two Pointer** approach.

* Initialize one pointer (`start`) at the beginning of the vector.
* Initialize another pointer (`end`) at the last index.
* Swap the characters at both pointers.
* Move `start` one step forward.
* Move `end` one step backward.
* Continue until both pointers meet.

This reverses the vector without using any extra memory.

---

# Algorithm

1. Initialize `start = 0`.
2. Initialize `end = size - 1`.
3. While `start < end`:

   * Swap `s[start]` and `s[end]`.
   * Increment `start`.
   * Decrement `end`.
4. Print the reversed vector.

---

# C++ Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    int start = 0;
    int end = s.size() - 1;

    while(start < end) {
        swap(s[start], s[end]);
        start++;
        end--;
    }

    for(int i = 0; i < s.size(); i++) {
        cout << s[i] << " ";
    }

    return 0;
}
```

---

# Dry Run

### Initial Vector

```text
h e l l o
```

### Step 1

Swap `h` and `o`

```text
o e l l h
```

---

### Step 2

Swap `e` and `l`

```text
o l l e h
```

---

### Step 3

Now,

```text
start = 2
end = 2
```

Since `start` is no longer less than `end`, the loop stops.

---

### Final Output

```text
o l l e h
```

---

# Time Complexity

Each character is visited at most once.

```text
O(n)
```

where **n** is the number of characters in the vector.

---

# Space Complexity

The algorithm reverses the vector in-place without using any additional data structures.

```text
O(1)
```

---

# Advantages

* Efficient and simple implementation.
* In-place reversal (no extra array required).
* Linear time complexity.
* Constant extra space.

---

# Disadvantages

* Modifies the original vector.
* Not suitable if the original order must be preserved.

---

# Key Concept

The **Two Pointer Technique** is commonly used for problems involving:

* Reversing arrays or strings
* Palindrome checking
* Removing duplicates
* Searching in sorted arrays
* Sliding window problems

Mastering this technique is essential for coding interviews and competitive programming.

---

# Learning Outcomes

After completing this implementation, you will understand:

* The Two Pointer technique
* In-place array/string manipulation
* Swapping elements in C++
* Time and Space Complexity analysis
* Efficient string reversal algorithms

---

# Author

**Ameer Hamza**

Data Structures & Algorithms (DSA) Practice | C++ Solutions
