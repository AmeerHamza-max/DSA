# 622. Design Circular Queue

## 📌 Problem Statement

Design a Circular Queue (Ring Buffer) without using the built-in queue data structure.

Implement the following operations:

- `enQueue(value)` → Insert an element into the queue.
- `deQueue()` → Remove the front element.
- `Front()` → Return the front element.
- `Rear()` → Return the last element.
- `isEmpty()` → Check whether the queue is empty.
- `isFull()` → Check whether the queue is full.

A circular queue reuses empty spaces by connecting the last position back to the first position.

---

## 💡 Approach

Instead of shifting elements after every deletion, maintain two pointers:

- `front` → Points to the first element.
- `rear` → Points to the last element.

Also maintain:

- `size` → Current number of elements.
- `capacity` → Maximum size of the queue.

A vector of size `k` is used to store the elements.

To move the pointers in a circular manner, use:

```cpp
(pointer + 1) % capacity
```

This wraps the pointer back to index `0` after reaching the last index.

---

## 🧠 Algorithm

### Constructor

- Create a vector of size `k`.
- Initialize:
  - `front = 0`
  - `rear = -1`
  - `size = 0`
  - `capacity = k`

### enQueue(value)

1. If the queue is full, return `false`.
2. Move the rear pointer:
   ```cpp
   rear = (rear + 1) % capacity;
   ```
3. Insert the value.
4. Increment `size`.
5. Return `true`.

### deQueue()

1. If the queue is empty, return `false`.
2. Move the front pointer:
   ```cpp
   front = (front + 1) % capacity;
   ```
3. Decrement `size`.
4. Return `true`.

### Front()

- Return `-1` if the queue is empty.
- Otherwise, return the element at `front`.

### Rear()

- Return `-1` if the queue is empty.
- Otherwise, return the element at `rear`.

### isEmpty()

- Return `true` if `size == 0`.

### isFull()

- Return `true` if `size == capacity`.

---

## ✅ Key Idea

The circular queue avoids shifting elements after deletion.

Instead of moving data, only the `front` and `rear` pointers are updated using modulo arithmetic:

```cpp
(pointer + 1) % capacity
```

This allows the queue to reuse empty positions efficiently.

---

## ⏱️ Complexity Analysis

| Operation | Time Complexity |
|-----------|-----------------|
| enQueue() | O(1) |
| deQueue() | O(1) |
| Front() | O(1) |
| Rear() | O(1) |
| isEmpty() | O(1) |
| isFull() | O(1) |

### Space Complexity

- **O(k)**

where `k` is the capacity of the circular queue.

---

## 🏷️ Topics

- Design
- Queue
- Circular Queue
- Array
- Simulation

---

## 📚 What I Learned

- How to implement a circular queue using an array (vector).
- How to use `front` and `rear` pointers efficiently.
- How modulo (`%`) helps in wrapping indices.
- Difference between a normal queue and a circular queue.
- How to maintain queue state using `size` and `capacity`.
- Designing data structures without using built-in STL containers.