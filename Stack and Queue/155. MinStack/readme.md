# 155. Min Stack

## 🟢 Problem

Design a stack that supports the following operations in **O(1)** time:

- `push(val)` → Push an element onto the stack.
- `pop()` → Remove the top element.
- `top()` → Return the top element.
- `getMin()` → Return the minimum element currently in the stack.

---

## 💡 Approach

A single stack is not enough because after removing the current minimum element, we would have to search the entire stack again to find the new minimum, which takes **O(n)** time.

To achieve **O(1)** time for all operations, we use **two stacks** (implemented using two vectors):

1. **Main Stack (`st`)**
   - Stores all the elements.

2. **Minimum Stack (`minSt`)**
   - Stores the minimum element at every level of the main stack.

### How it works

### Push

- Push the value into the main stack.
- If the minimum stack is empty, push the value.
- Otherwise, push the smaller value between:
  - the current value
  - the current minimum (`minSt.back()`)

```cpp
minSt.push_back(min(value, minSt.back()));
```

---

### Pop

Remove the top element from both stacks.

---

### Top

Return the last element of the main stack.

---

### Get Minimum

Return the last element of the minimum stack.

---

## 📖 Dry Run

### Operations

```text
push(5)
push(2)
push(8)
push(1)
```

| Main Stack | Min Stack |
|------------|-----------|
| 5 | 5 |
| 5, 2 | 5, 2 |
| 5, 2, 8 | 5, 2, 2 |
| 5, 2, 8, 1 | 5, 2, 2, 1 |

### pop()

Remove `1`

| Main Stack | Min Stack |
|------------|-----------|
| 5, 2, 8 | 5, 2, 2 |

Current minimum = **2**

---

## ✅ Algorithm

1. Create two vectors:
   - `st` → Stores all values.
   - `minSt` → Stores the minimum value at each position.
2. For every push:
   - Push the value into `st`.
   - Push `min(value, currentMin)` into `minSt`.
3. For pop:
   - Remove the last element from both vectors.
4. Return `st.back()` for `top()`.
5. Return `minSt.back()` for `getMin()`.

---

## ⏱️ Time Complexity

| Operation | Complexity |
|-----------|------------|
| Push | **O(1)** |
| Pop | **O(1)** |
| Top | **O(1)** |
| Get Minimum | **O(1)** |

---

## 💾 Space Complexity

- **O(n)**

We maintain two stacks, each storing at most `n` elements.

---

## ✅ Key Learning

- A single stack cannot maintain the minimum element in **O(1)** after popping the current minimum.
- A second stack stores the minimum value at every level.
- The top of the second stack always represents the current minimum.
- Using two stacks allows all operations to run in **constant time**.

---

## 🏷️ Topics

- Stack
- Design
- Data Structures
- Vector
- Simulation

---

## 🚀 LeetCode

**Problem:** 155. Min Stack