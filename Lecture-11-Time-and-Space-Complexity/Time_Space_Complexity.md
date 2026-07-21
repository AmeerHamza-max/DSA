# ⏱️ Time & Space Complexity — Complete Guide

> **Goal:** Understand how to measure algorithm efficiency so you can write better, faster, and smarter code.

---

## 📌 Table of Contents

1. [What is Complexity?](#what-is-complexity)
2. [Why Does It Matter?](#why-does-it-matter)
3. [Types of Notation](#types-of-notation)
4. [Big O Notation (Deep Dive)](#big-o-notation-deep-dive)
5. [Common Time Complexities](#common-time-complexities)
6. [Complexity Hierarchy](#complexity-hierarchy)
7. [How to Calculate Big O](#how-to-calculate-big-o)
8. [Space Complexity](#space-complexity)
9. [Complexity Cheat Sheet](#complexity-cheat-sheet)
10. [Practice Problems](#practice-problems)
11. [Key Takeaways](#key-takeaways)

---

## What is Complexity?

**Time Complexity** is the amount of time taken by an algorithm to run **as a function of the length of the input**.

**Space Complexity** is the amount of **memory** an algorithm uses as a function of the input size.

Think of it like this:

| Real-World Analogy | Algorithm Concept |
|--------------------|-------------------|
| How long does it take to find a name in a phonebook? | Time Complexity |
| How much paper do you need to solve a math problem? | Space Complexity |

---

## Why Does It Matter?

Two algorithms can solve the same problem but perform very differently:

```
Algorithm A — High Processing, Slow  ❌
Algorithm B — Low Processing, Fast   ✅
```

When input size grows to millions (real-world apps, databases, search engines), a bad algorithm can take **hours** while a good one takes **milliseconds**.

**Example:**
- Searching 1,000,000 records
- O(n) → 1,000,000 steps
- O(log n) → only ~20 steps ✅

---

## Types of Notation

There are three main notations used to describe complexity:

| Notation | Symbol | Meaning | Use Case |
|----------|--------|---------|----------|
| **Big O** | O(...) | Upper Bound — Worst Case | Most commonly used |
| **Theta** | θ(...) | Tight Bound — Average Case | Exact behavior |
| **Omega** | Ω(...) | Lower Bound — Best Case | Best possible scenario |

> 💡 **In interviews and daily coding, we almost always use Big O** because we care about how bad things can get (worst case).

---

## Big O Notation (Deep Dive)

### What is Big O?

Big O notation gives us the **upper bound** of an algorithm's running time.

It answers: **"In the worst case, how many steps will this algorithm take?"**

### Rules of Big O

1. **Drop constants** — O(2n) becomes O(n)
2. **Drop lower-order terms** — O(n² + n) becomes O(n²)
3. **Pick the dominant term** — the one that grows fastest wins

---

## Common Time Complexities

### 1. 🟢 Constant Time — O(1)

The algorithm always takes the **same amount of time**, no matter the input size.

```javascript
// No matter how big n is, this loop always runs exactly 10 times
for (let i = 0; i < 10; i++) {
  console.log("Hello");
}

// Accessing an array element by index — always 1 step
const arr = [10, 20, 30, 40, 50];
console.log(arr[2]); // O(1)
```

**Real-world example:** Looking up a value in a HashMap by key.

**Graph behavior:** Flat horizontal line — never changes.

---

### 2. 🟡 Linear Time — O(n)

The time grows **directly proportional** to the input size.

```javascript
// Loop runs n times — as n grows, time grows equally
for (let i = 0; i < n; i++) {
  console.log("Hello");
}

// Searching through an array without sorting
function linearSearch(arr, target) {
  for (let i = 0; i < arr.length; i++) { // O(n)
    if (arr[i] === target) return i;
  }
  return -1;
}
```

**Real-world example:** Reading every line in a file, printing all users in a list.

**Graph behavior:** Straight diagonal line.

---

### 3. 🔵 Logarithmic Time — O(log n)

The time grows **very slowly** — each step cuts the problem **in half**.

```javascript
// Binary Search — classic O(log n) algorithm
function binarySearch(arr, target) {
  let left = 0;
  let right = arr.length - 1;

  while (left <= right) {
    const mid = Math.floor((left + right) / 2); // Find middle

    if (arr[mid] === target) return mid;         // Found it
    else if (arr[mid] < target) left = mid + 1; // Search right half
    else right = mid - 1;                        // Search left half
  }

  return -1; // Not found
}
```

**How it works:** For n = 1,000,000 elements, binary search only needs ~20 steps!

**Real-world example:** Searching in a sorted database, dictionary lookup, Git bisect.

**Graph behavior:** Curve that flattens quickly.

---

### 4. 🟠 Quadratic Time — O(n²)

Time grows as the **square of the input**. Usually caused by **nested loops**.

```javascript
// Two nested loops — for each element, we loop through all elements again
for (let i = 0; i < n; i++) {       // Outer loop: n times
  for (let j = 0; j < n; j++) {     // Inner loop: n times each
    console.log(i, j);
  }
}
// Total: n × n = n² steps

// Bubble Sort — classic O(n²) algorithm
function bubbleSort(arr) {
  const n = arr.length;
  for (let i = 0; i < n; i++) {           // O(n)
    for (let j = 0; j < n - i - 1; j++) { // O(n)
      if (arr[j] > arr[j + 1]) {
        [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]]; // Swap
      }
    }
  }
  return arr;
}
```

**Real-world example:** Naive duplicate detection, simple sorting algorithms (Bubble, Selection, Insertion Sort).

**Graph behavior:** Steep upward curve. Gets slow fast for large inputs.

---

### 5. 🔴 Cubic Time — O(n³)

Three nested loops. Gets **very slow** very quickly.

```javascript
// Triple nested loop
for (let i = 0; i < n; i++) {       // n times
  for (let j = 0; j < n; j++) {     // n times
    for (let k = 0; k < n; k++) {   // n times
      console.log(i, j, k);
    }
  }
}
// Total: n × n × n = n³ steps
```

**Real-world example:** Matrix multiplication (naive), Floyd-Warshall algorithm for all-pairs shortest path.

**Tip:** Avoid O(n³) for n > 400. It becomes impractical quickly.

---

### 6. 🟣 Linearithmic Time — O(n log n)

Better than O(n²), this is the **sweet spot** for many sorting algorithms.

```javascript
// Merge Sort — O(n log n)
function mergeSort(arr) {
  if (arr.length <= 1) return arr;

  const mid = Math.floor(arr.length / 2);
  const left = mergeSort(arr.slice(0, mid));   // log n splits
  const right = mergeSort(arr.slice(mid));      // log n splits

  return merge(left, right);                    // n merges per level
}

function merge(left, right) {
  const result = [];
  let i = 0, j = 0;

  while (i < left.length && j < right.length) {
    if (left[i] <= right[j]) result.push(left[i++]);
    else result.push(right[j++]);
  }

  return [...result, ...left.slice(i), ...right.slice(j)];
}
```

**Real-world example:** JavaScript's built-in `.sort()`, database indexing, efficient sorting everywhere.

---

### 7. 💀 Exponential Time — O(2ⁿ)

The time **doubles** with every additional input. Extremely slow.

```javascript
// Finding all subsets (Power Set)
function powerSet(arr) {
  if (arr.length === 0) return [[]];

  const first = arr[0];
  const rest = powerSet(arr.slice(1)); // O(2^n)

  return [...rest, ...rest.map(set => [first, ...set])];
}
// Input of 20 elements → over 1,000,000 subsets
```

**Real-world example:** Brute-force password cracking, naive solving of NP-hard problems.

---

### 8. 💀 Factorial Time — O(n!)

The worst common complexity. Only feasible for very small inputs (n ≤ 10–11).

```javascript
// Generating all permutations
function permutations(arr) {
  if (arr.length <= 1) return [arr];
  const result = [];

  for (let i = 0; i < arr.length; i++) {
    const rest = [...arr.slice(0, i), ...arr.slice(i + 1)];
    for (const perm of permutations(rest)) {
      result.push([arr[i], ...perm]);
    }
  }

  return result;
}
// n=10 → 3,628,800 permutations
// n=12 → 479,001,600 permutations — already very slow!
```

**Real-world example:** Brute-force Traveling Salesman Problem, generating all arrangements.

---

## Complexity Hierarchy

From **fastest** (best) to **slowest** (worst):

```
O(1)  <  O(log n)  <  O(n)  <  O(n log n)  <  O(n²)  <  O(n³)  <  O(2ⁿ)  <  O(n!)
```

### Practical Input Size Limits

Use this table to know which complexity is acceptable for a given input size:

| Complexity | Max Input Size (n) | Notes |
|---|---|---|
| O(n!) | ≤ 10–11 | Extremely limited |
| O(2ⁿ · n²) | ≤ 15–18 | Very small inputs only |
| O(n⁴) | < 100 | Very slow growth |
| O(n³) | < 400 | Avoid for large data |
| O(n² · log n) | < 2,000 | Use carefully |
| O(n²) | < 10,000 (10⁴) | Acceptable for small data |
| O(n log n) | < 1,000,000 (10⁶) | Great for most problems |
| O(n), O(log n) | ≤ 10⁸ | Ideal for large data |

---

## How to Calculate Big O

### Rule 1: Drop Constants

```javascript
// This is O(2n) — but we simplify to O(n)
for (let i = 0; i < n; i++) { console.log(i); } // n steps
for (let j = 0; j < n; j++) { console.log(j); } // n steps
// Total: 2n → O(n)
```

### Rule 2: Pick the Dominant Term

```
f(n) = 2n² + 3n     → O(n²)   ← n² dominates
f(n) = 2n⁴ + 3n³   → O(n⁴)   ← n⁴ dominates
f(n) = 1200         → O(1)    ← constant, no n
```

**Why?** As n grows to infinity, lower-order terms become insignificant:
- When n = 1,000: n² = 1,000,000 vs n = 1,000 → n² completely dominates

### Rule 3: Nested Loops Multiply

```javascript
// Single loop → O(n)
for (let i = 0; i < n; i++) { }

// Nested loop → O(n × n) = O(n²)
for (let i = 0; i < n; i++) {
  for (let j = 0; j < n; j++) { }
}

// Triple nested → O(n × n × n) = O(n³)
for (let i = 0; i < n; i++) {
  for (let j = 0; j < n; j++) {
    for (let k = 0; k < n; k++) { }
  }
}
```

### Rule 4: Sequential Blocks Add

```javascript
// Block 1: O(n)
for (let i = 0; i < n; i++) { }

// Block 2: O(n²)
for (let i = 0; i < n; i++) {
  for (let j = 0; j < n; j++) { }
}

// Total: O(n) + O(n²) → O(n²)  ← dominant term wins
```

---

## Space Complexity

Space complexity measures how much **extra memory** your algorithm uses.

### O(1) — Constant Space

Using a fixed number of variables — no extra memory regardless of input size.

```javascript
// Only 3 variables created, no matter how big the array is
function findMax(arr) {
  let max = arr[0];   // O(1) space
  let index = 0;      // O(1) space
  let count = 0;      // O(1) space

  for (let i = 1; i < arr.length; i++) {
    if (arr[i] > max) {
      max = arr[i];
      index = i;
    }
    count++;
  }

  return { max, index };
}
// Space Complexity: O(1) — only 3 variables, always
```

### O(n) — Linear Space

Memory grows proportionally with input size.

```javascript
// Creating a new array of size n
function doubleAll(arr) {
  const result = new Array(arr.length); // O(n) space — grows with input

  for (let i = 0; i < arr.length; i++) {
    result[i] = arr[i] * 2;
  }

  return result;
}
// Space Complexity: O(n) — result array scales with input
```

```javascript
// HashMap / Frequency Counter
function frequencyCount(arr) {
  const freq = {}; // In worst case, holds n entries → O(n) space

  for (const item of arr) {
    freq[item] = (freq[item] || 0) + 1;
  }

  return freq;
}
// Space Complexity: O(n)
```

### O(n²) — Quadratic Space

Creating a 2D grid/matrix of size n × n.

```javascript
// Creating an n×n matrix
function createGrid(n) {
  const grid = [];

  for (let i = 0; i < n; i++) {
    grid[i] = new Array(n).fill(0); // n rows, n columns
  }

  return grid;
}
// Space Complexity: O(n²) — n × n cells in memory
```

### Space Complexity Summary

| What You Create | Space Complexity |
|---|---|
| A few variables (int, bool, pointer) | O(1) |
| An array/list of size n | O(n) |
| A 2D matrix of size n × n | O(n²) |
| A HashMap with up to n entries | O(n) |

---

## Complexity Cheat Sheet

### Common Algorithms & Their Complexities

| Algorithm | Time Complexity | Space Complexity |
|---|---|---|
| Array access by index | O(1) | O(1) |
| Linear Search | O(n) | O(1) |
| Binary Search | O(log n) | O(1) |
| Bubble Sort | O(n²) | O(1) |
| Merge Sort | O(n log n) | O(n) |
| Quick Sort | O(n log n) avg | O(log n) |
| Hash Table lookup | O(1) avg | O(n) |
| Matrix multiplication | O(n³) | O(n²) |

---

## Practice Problems

### 🟢 Beginner

**Problem 1:** What is the time complexity of this code?

```javascript
function mystery(arr) {
  let sum = 0;
  for (let i = 0; i < arr.length; i++) {
    sum += arr[i];
  }
  return sum;
}
```
*Answer: O(n) — one loop through the array*

---

**Problem 2:** What is the time complexity?

```javascript
function check(n) {
  if (n % 2 === 0) return "even";
  return "odd";
}
```
*Answer: O(1) — single operation, no loops*

---

**Problem 3:** What is the space complexity?

```javascript
function createList(n) {
  const list = [];
  for (let i = 0; i < n; i++) {
    list.push(i * 2);
  }
  return list;
}
```
*Answer: O(n) — creating a list of size n*

---

### 🟡 Intermediate

**Problem 4:** Find the time complexity and explain why.

```javascript
function findPair(arr, target) {
  const seen = {};
  for (let i = 0; i < arr.length; i++) {
    const complement = target - arr[i];
    if (seen[complement]) return [complement, arr[i]];
    seen[arr[i]] = true;
  }
  return null;
}
```
*Answer: O(n) time, O(n) space — one loop + HashMap*

---

**Problem 5:** What is the time complexity of this nested structure?

```javascript
function countPairs(arr) {
  let count = 0;
  for (let i = 0; i < arr.length; i++) {       // O(n)
    for (let j = i + 1; j < arr.length; j++) { // O(n)
      if (arr[i] + arr[j] === 10) count++;
    }
  }
  return count;
}
```
*Answer: O(n²) — nested loops (even though inner starts at i+1, it's still n²)*

---

**Problem 6:** Calculate the overall complexity.

```javascript
function process(arr) {
  // Step 1
  arr.sort((a, b) => a - b);   // O(n log n)

  // Step 2
  let sum = 0;
  for (let x of arr) sum += x; // O(n)

  return sum;
}
```
*Answer: O(n log n) — dominant term wins over O(n)*

---

### 🔴 Advanced

**Problem 7:** What is the space complexity of generating all subsets?

```javascript
function subsets(nums) {
  const result = [[]];
  for (const num of nums) {
    const newSubsets = result.map(sub => [...sub, num]);
    result.push(...newSubsets);
  }
  return result;
}
```
*Answer: O(2ⁿ) time and space — each element doubles the number of subsets*

---

**Problem 8 (Challenge — Interview Level):**

You have an algorithm with the following structure:

```javascript
function mystery(n) {
  for (let i = 0; i < n; i++) {          // Loop A
    for (let j = 0; j < n; j++) {        // Loop B
      console.log(i + j);
    }
  }

  for (let k = 0; k < n; k++) {          // Loop C
    console.log(k);
  }
}
```

What is the time and space complexity? Justify your answer step by step.

*Answer: Time = O(n²) + O(n) = O(n²) | Space = O(1) — only loop counters used*

---

## Key Takeaways

```
✅ Big O = Worst Case (Upper Bound)
✅ Always drop constants: O(3n) → O(n)
✅ Always pick the dominant term: O(n² + n) → O(n²)
✅ Nested loops multiply: 2 loops → O(n²), 3 loops → O(n³)
✅ Sequential blocks add, then simplify to dominant
✅ Space complexity = extra memory used (not input memory)
✅ Creating a variable = O(1) space
✅ Creating an array of n elements = O(n) space
```

### The Golden Rule

> **Write the simplest code that works within acceptable complexity for your input size.**

If n ≤ 1,000 → O(n²) is fine.
If n ≤ 1,000,000 → you need at least O(n log n).
If n ≤ 10⁸ → you need O(n) or O(log n).

---

*Made for intermediate learners targeting interviews and professional development.*
*Practice daily. Complexity becomes intuitive with repetition.*
