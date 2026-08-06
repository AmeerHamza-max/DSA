# 1700. Number of Students Unable to Eat Lunch

## 📌 Problem Statement

You are given:

- A queue of students where:
  - `0` = prefers circular sandwich
  - `1` = prefers square sandwich
- A stack of sandwiches where the first element is the top of the stack.

Rules:

1. The student at the front of the queue checks the top sandwich.
2. If the sandwich matches the student's preference:
   - The student takes the sandwich and leaves.
   - The sandwich is removed from the stack.
3. Otherwise:
   - The student moves to the end of the queue.
4. The process stops when no student wants the sandwich on top.

Return the number of students who cannot eat.

---

## 💡 Approach (Queue Simulation)

We simulate the process exactly as described.

### Steps

1. Push all students into a queue.
2. Use an index `i` to point to the current sandwich.
3. If the front student matches the current sandwich:
   - Remove the student.
   - Move to the next sandwich.
   - Reset the counter.
4. Otherwise:
   - Move the student to the back of the queue.
   - Increase the counter.
5. If every student has been moved once without taking the current sandwich, stop.
6. Return the number of remaining students.

---

## 🧠 Key Idea

A variable `count` keeps track of how many consecutive students failed to take the current sandwich.

- If a student eats, reset `count = 0`.
- If a student is moved to the back, increment `count`.
- When `count == queue.size()`, it means every remaining student has already rejected the current sandwich.

At that point, no further progress is possible, so we stop.

---

## ✅ Algorithm

1. Insert all students into a queue.
2. Set sandwich index `i = 0`.
3. While the queue is not empty:
   - If the front student likes the current sandwich:
     - Remove the student.
     - Move to the next sandwich.
     - Reset `count`.
   - Otherwise:
     - Move the student to the back.
     - Increment `count`.
   - If `count == queue.size()`, stop.
4. Return the remaining queue size.

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)` (Worst Case)
- **Space Complexity:** `O(n)`

where `n` is the number of students.

---

## 🏷️ Topics

- Queue
- Simulation
- Stack
- Greedy

---

## 📚 What I Learned

- How to simulate queue operations using C++ STL.
- Difference between Queue (FIFO) and Stack (LIFO).
- How to detect when a simulation should stop to avoid an infinite loop.
- Using a counter to determine when every student has rejected the current sandwich.