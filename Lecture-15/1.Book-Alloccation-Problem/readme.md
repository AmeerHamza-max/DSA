# 📚 Book Allocation Problem

## 📌 Problem Statement

You are given an array where each element represents the number of pages in a book. These books must be allocated to a given number of students following these rules:

* Every student must receive at least one book.
* Books are allocated in contiguous order.
* A book cannot be divided among multiple students.
* The objective is to minimize the maximum number of pages assigned to any student.

---

## 💡 Approach

This problem is solved using **Binary Search on Answer**.

### Step 1: Define the Search Space

* **Minimum possible answer:** Maximum pages in a single book.
* **Maximum possible answer:** Sum of all pages.

Example:

Books = `[10, 20, 30, 40]`

* Minimum = `40`
* Maximum = `100`

So the answer lies between **40** and **100**.

---

### Step 2: Binary Search

Calculate the middle value.

```
mid = (start + end) / 2
```

Treat `mid` as the maximum number of pages a student is allowed to receive.

Now check whether all books can be allocated under this limit.

---

### Step 3: Feasibility Check

Traverse the array.

* If adding the current book does not exceed `mid`, assign it to the current student.
* Otherwise, allocate a new student.
* If the number of students exceeds `m`, allocation is not possible.

---

### Step 4: Update Binary Search

* If allocation is possible:

  * Save the answer.
  * Search for a smaller value.
* Otherwise:

  * Search for a larger value.

Repeat until `start > end`.

---

## 🧠 Algorithm

1. If the number of students is greater than the number of books, return `-1`.
2. Calculate the total number of pages.
3. Set:

   * `start = maximum pages in a single book`
   * `end = total pages`
4. Perform Binary Search.
5. For every `mid`, check if allocation is possible.
6. If possible:

   * Store the answer.
   * Move left.
7. Else:

   * Move right.
8. Return the stored answer.

---

## ✅ Example

### Input

```
Books = [10, 20, 30, 40]
Students = 2
```

### Allocation

```
Student 1 → 10 + 20 + 30 = 60
Student 2 → 40
```

Maximum pages assigned = **60**

### Output

```
60
```

---

## ⏱️ Time Complexity

### Binary Search

```
O(log(sum))
```

### Feasibility Check

```
O(n)
```

### Overall

```
O(n × log(sum))
```

where:

* `n` = Number of books
* `sum` = Total pages of all books

---

## 💾 Space Complexity

```
O(1)
```

Only a few extra variables are used.

---

## 🔍 Dry Run

### Input

```
Books = [10, 20, 30, 40]
Students = 2
```

Search Space:

```
start = 40
end = 100
```

### Iteration 1

```
mid = 70
```

Allocation:

```
Student 1 → 10 + 20 + 30 = 60
Student 2 → 40
```

Possible ✅

Answer = 70

Search Left

---

### Iteration 2

```
mid = 54
```

Allocation:

```
Student 1 → 10 + 20 = 30
Student 2 → 30
Student 3 → 40
```

Need 3 students ❌

Search Right

---

### Iteration 3

```
mid = 62
```

Allocation:

```
Student 1 → 10 + 20 + 30 = 60
Student 2 → 40
```

Possible ✅

Answer = 62

Search Left

---

### Iteration 4

```
mid = 58
```

Need 3 students ❌

Search Right

---

### Iteration 5

```
mid = 60
```

Allocation:

```
Student 1 → 10 + 20 + 30 = 60
Student 2 → 40
```

Possible ✅

Answer = 60

Search Left

Binary Search Ends.

Final Answer:

```
60
```

---

## 🎯 Key Learning

* Binary Search can be applied to the **answer**, not just to arrays.
* Use Binary Search when:

  * The answer lies within a range.
  * A feasibility function (`isPossible`) can determine whether a candidate answer is valid.
* This technique is commonly known as **Binary Search on Answer**.

---

## 🚀 Concepts Used

* Binary Search
* Greedy Allocation
* Search Space Optimization
* Contiguous Partitioning
* Feasibility Checking
* Arrays
* Functions

---

## 📖 Conclusion

The Book Allocation Problem is a classic Binary Search on Answer problem. Instead of searching for an index, we search for the minimum possible maximum pages that can be assigned to any student. By combining Binary Search with a greedy feasibility check, the solution efficiently finds the optimal answer in **O(n × log(sum))** time while using **O(1)** extra space.
