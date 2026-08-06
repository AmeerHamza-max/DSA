# 232. Implement Queue using Stacks

## Problem Statement

Implement a **First In First Out (FIFO)** queue using only two stacks.

The queue should support the following operations:

- `push(x)` → Insert an element at the back of the queue.
- `pop()` → Remove and return the front element.
- `peek()` → Return the front element without removing it.
- `empty()` → Return `true` if the queue is empty, otherwise `false`.

**LeetCode:** 232 - Implement Queue using Stacks

---

## Approach

A queue follows the **FIFO (First In First Out)** principle, while a stack follows **LIFO (Last In First Out)**. To simulate a queue using stacks, we use two stacks:

- **s1** → Used for inserting new elements.
- **s2** → Used for removing and accessing the front element.

### Push Operation

- Push every new element into `s1`.

### Pop Operation

- If `s2` is empty, move all elements from `s1` to `s2`.
- This reverses the order, making the oldest element appear on the top of `s2`.
- Pop the top element from `s2`.

### Peek Operation

- If `s2` is empty, transfer all elements from `s1` to `s2`.
- Return the top element of `s2`.

### Empty Operation

- The queue is empty only if both `s1` and `s2` are empty.

---

## Algorithm

1. Create two stacks `s1` and `s2`.
2. For `push(x)`, insert `x` into `s1`.
3. For `pop()`:
   - If `s2` is empty, move all elements from `s1` to `s2`.
   - Pop and return the top of `s2`.
4. For `peek()`:
   - If `s2` is empty, transfer all elements from `s1` to `s2`.
   - Return the top of `s2`.
5. For `empty()`:
   - Return `true` if both stacks are empty.

---

## Example

```
Operations:

push(1)
push(2)
push(3)

s1:
3
2
1

s2:
empty

pop()

Transfer s1 → s2

s2:
1
2
3

Pop:
1

Queue becomes:
2 3
```

---

## Time Complexity

| Operation | Time Complexity |
|-----------|-----------------|
| push() | O(1) |
| pop() | O(1) Amortized |
| peek() | O(1) Amortized |
| empty() | O(1) |

---

## Space Complexity

- **O(n)**

Two stacks are used to store all queue elements.

---

## Key Concept

The expensive transfer from `s1` to `s2` happens **only when `s2` becomes empty**.

Each element is:

- Pushed once into `s1`
- Moved once to `s2`
- Popped once from `s2`

Therefore, although a single `pop()` or `peek()` may take **O(n)** during a transfer, the overall cost of **n operations is O(n)**. This gives an **amortized time complexity of O(1)** per operation.

---

## Topics

- Stack
- Queue
- Design
- Data Structure
- Amortized Analysis