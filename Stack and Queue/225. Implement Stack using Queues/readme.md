# 225. Implement Stack using Queues

## Problem Statement

Implement a **Last In First Out (LIFO)** stack using only two queues.

The stack should support the following operations:

- `push(x)` → Push an element onto the stack.
- `pop()` → Remove and return the top element.
- `top()` → Return the top element without removing it.
- `empty()` → Return `true` if the stack is empty, otherwise `false`.

**LeetCode:** 225 - Implement Stack using Queues

---

## Approach

A stack follows the **LIFO (Last In First Out)** principle, while a queue follows **FIFO (First In First Out)**. To simulate a stack using queues, we use two queues:

- **q1** → Stores the current stack elements.
- **q2** → Temporary queue used during the push operation.

### Push Operation

1. Push the new element into `q2`.
2. Move all elements from `q1` to `q2`.
3. Swap `q1` and `q2`.

After these steps, the newest element is always at the front of `q1`, making stack operations easy.

### Pop Operation

- Remove and return the front element of `q1`.

### Top Operation

- Return the front element of `q1`.

### Empty Operation

- Return `true` if `q1` is empty.

---

## Algorithm

1. Create two queues `q1` and `q2`.
2. For `push(x)`:
   - Push `x` into `q2`.
   - Move all elements from `q1` to `q2`.
   - Swap `q1` and `q2`.
3. For `pop()`:
   - Store `q1.front()`.
   - Remove it using `pop()`.
   - Return the stored value.
4. For `top()`:
   - Return `q1.front()`.
5. For `empty()`:
   - Return `q1.empty()`.

---

## Example

```
push(1)

q1:
1

push(2)

q2:
2

Move q1 → q2

q2:
2 1

Swap

q1:
2 1

top() -> 2

pop() -> 2

Remaining Stack:
1
```

---

## Time Complexity

| Operation | Time Complexity |
|-----------|-----------------|
| push() | O(n) |
| pop() | O(1) |
| top() | O(1) |
| empty() | O(1) |

---

## Space Complexity

- **O(n)**

Two queues are used to store all stack elements.

---

## Key Concept

The main idea is to make the **newly inserted element always stay at the front of `q1`**.

During every `push()`:

- Insert the new element into `q2`.
- Move all previous elements from `q1` to `q2`.
- Swap the queues.

This ensures that the front of `q1` always represents the **top of the stack**, making both `pop()` and `top()` operations **O(1)**.

---

## Topics

- Queue
- Stack
- Design
- Data Structure
- Simulation
```