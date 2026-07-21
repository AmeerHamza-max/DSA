# Selection Sort in C++

## Overview

This project demonstrates the implementation of the **Selection Sort** algorithm in C++.

Selection Sort is a simple comparison-based sorting algorithm. It repeatedly selects the smallest element from the unsorted portion of the array and places it at the beginning. After each pass, the sorted portion of the array grows by one element until the entire array is sorted.

Although Selection Sort is easy to understand and implement, it is not suitable for large datasets due to its quadratic time complexity.

---

# Problem Statement

Given an array of integers:

```cpp
{20, 15, 25, 21, 24, 9}
```

Sort the array in **ascending order** using the **Selection Sort** algorithm.

---

# Solution

The solution uses the **Selection Sort** algorithm.

The array is divided into two parts:

* **Sorted Portion** – Initially empty.
* **Unsorted Portion** – Contains all elements.

For every position in the array:

1. Assume the current element is the smallest.
2. Traverse the remaining unsorted portion to find the actual minimum element.
3. Swap the minimum element with the current element.
4. Repeat the same process until the array becomes completely sorted.

The sorting is performed **in-place**, meaning no extra array is created.

---

# Algorithm

1. Start from the first index of the array.
2. Assume the current index contains the minimum element.
3. Traverse the remaining unsorted portion of the array.
4. Update the minimum index whenever a smaller element is found.
5. Swap the smallest element with the current element.
6. Repeat the process for all positions except the last one.

---

# C++ Code

```cpp
#include<iostream>
using namespace std;

int main() {

    int arr[6] = {20, 15, 25, 21, 24, 9};

    for(int i = 0; i < 5; i++) {

        int min = i;

        for(int j = i + 1; j < 6; j++) {

            if(arr[j] < arr[min]) {
                min = j;
            }

        }

        swap(arr[min], arr[i]);
    }

    for(int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
```

---

# Dry Run

### Initial Array

```text
20 15 25 21 24 9
```

---

### Pass 1

Minimum element = **9**

Swap **20** and **9**

```text
9 15 25 21 24 20
```

---

### Pass 2

Minimum element = **15**

Already in its correct position.

```text
9 15 25 21 24 20
```

---

### Pass 3

Minimum element = **20**

Swap **25** and **20**

```text
9 15 20 21 24 25
```

---

### Pass 4

Minimum element = **21**

Already in its correct position.

```text
9 15 20 21 24 25
```

---

### Pass 5

Minimum element = **24**

Already in its correct position.

```text
9 15 20 21 24 25
```

---

# Output

```text
9 15 20 21 24 25
```

---

# Time Complexity

Assume the array contains **n** elements.

### Number of Comparisons

During sorting, the algorithm performs:

```text
(n - 1) + (n - 2) + (n - 3) + ... + 2 + 1
```

Using the arithmetic series formula:

```text
n(n - 1) / 2
```

Ignoring constants and lower-order terms:

## Best Case

```text
O(n²)
```

Even if the array is already sorted, Selection Sort still searches for the minimum element in every pass.

---

## Average Case

```text
O(n²)
```

Every element is compared with the remaining unsorted elements.

---

## Worst Case

```text
O(n²)
```

The algorithm always performs the same number of comparisons regardless of the input order.

---

# Space Complexity

Selection Sort only uses a few extra variables:

* `i`
* `j`
* `min`

No additional array or data structure is required.

```text
O(1)
```

Therefore, Selection Sort is an **in-place sorting algorithm**.

---

# Stability

Selection Sort is **not a stable sorting algorithm**.

### Example

Original Array

```text
4A 5 4B 3
```

After Selection Sort

```text
3 4B 4A 5
```

Although the values are correctly sorted, the relative order of `4A` and `4B` changes.

Hence, Selection Sort is **unstable**.

---

# Advantages

* Easy to understand and implement.
* Requires only constant extra memory.
* Performs fewer swaps compared to Bubble Sort.
* Suitable for learning sorting algorithms.
* Works well for small datasets.

---

# Disadvantages

* Inefficient for large datasets.
* Time complexity remains **O(n²)** in all cases.
* Not a stable sorting algorithm.
* Performs unnecessary comparisons even if the array is already sorted.

---

# Learning Outcomes

After completing this project, you will understand:

* Selection Sort algorithm
* Comparison-based sorting
* In-place sorting
* Stable vs Unstable sorting algorithms
* Time Complexity analysis
* Space Complexity analysis
* Swapping elements in C++
* Dry running a sorting algorithm

---

# Author

**Ameer Hamza**

**Data Structures & Algorithms (DSA) Practice | C++**
