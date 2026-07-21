# Insertion Sort in C++

## Overview

This program implements the **Insertion Sort** algorithm in C++ to sort an array in **ascending order**.

Insertion Sort works similarly to how people arrange playing cards in their hands. It builds the sorted portion of the array one element at a time by inserting each element into its correct position.

---

## Problem Statement

Given an unsorted array of integers:

```cpp
{12, 54, 23, 9, 4, 15}
```

Sort the array in **ascending order** using the **Insertion Sort** algorithm.

---

## Algorithm

1. Start from the second element (`index = 1`).
2. Store the current element in a temporary variable (`temp`).
3. Compare `temp` with all previous elements.
4. Shift every element greater than `temp` one position to the right.
5. Insert `temp` into its correct position.
6. Repeat until the entire array is sorted.

---

## Source Code

```cpp
#include<iostream>
using namespace std;

int main() {
    int arr[] = {12, 54, 23, 9, 4, 15};
    int n = 6;

    for(int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;

        for(; j >= 0; j--) {
            if(arr[j] > temp) {
                arr[j + 1] = arr[j];
            }
            else {
                break;
            }
        }

        arr[j + 1] = temp;
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
```

---

## Dry Run

### Initial Array

```
12 54 23 9 4 15
```

---

### Pass 1 (i = 1)

Current Element:

```
54
```

Compare with:

```
12
```

Since `54 > 12`, no shifting is required.

Array becomes:

```
12 54 23 9 4 15
```

---

### Pass 2 (i = 2)

Current Element:

```
23
```

Compare with:

```
54
```

Shift `54` to the right.

Compare with:

```
12
```

Stop because `12 < 23`.

Insert `23`.

Array becomes:

```
12 23 54 9 4 15
```

---

### Pass 3 (i = 3)

Current Element:

```
9
```

Shift:

```
54
23
12
```

Insert `9`.

Array becomes:

```
9 12 23 54 4 15
```

---

### Pass 4 (i = 4)

Current Element:

```
4
```

Shift:

```
54
23
12
9
```

Insert `4`.

Array becomes:

```
4 9 12 23 54 15
```

---

### Pass 5 (i = 5)

Current Element:

```
15
```

Shift:

```
54
23
```

Stop at `12`.

Insert `15`.

Final array:

```
4 9 12 15 23 54
```

---

## Output

```
4 9 12 15 23 54
```

---

## How Insertion Sort Works

Suppose the array is:

```
12 54 23 9 4 15
```

### Step 1

Sorted Part:

```
12
```

Unsorted Part:

```
54 23 9 4 15
```

---

### Step 2

Insert `54` into the sorted part.

```
12 54
```

---

### Step 3

Insert `23`.

```
12 23 54
```

---

### Step 4

Insert `9`.

```
9 12 23 54
```

---

### Step 5

Insert `4`.

```
4 9 12 23 54
```

---

### Step 6

Insert `15`.

```
4 9 12 15 23 54
```

Now the entire array is sorted.

---

## Time Complexity

| Case | Complexity |
|------|------------|
| Best Case | **O(n)** |
| Average Case | **O(n²)** |
| Worst Case | **O(n²)** |

### Explanation

- **Best Case:** The array is already sorted, so only one comparison is needed for each element.
- **Average Case:** Elements require a moderate number of shifts.
- **Worst Case:** The array is sorted in reverse order, so every element must be shifted.

---

## Space Complexity

| Complexity |
|------------|
| **O(1)** |

Insertion Sort is an **in-place sorting algorithm** because it uses only a constant amount of extra memory.

---

## Advantages

- Easy to understand and implement.
- In-place sorting algorithm.
- Stable sorting algorithm.
- Efficient for small datasets.
- Performs well when the array is already or nearly sorted.
- Requires no additional memory.

---

## Disadvantages

- Inefficient for large datasets.
- Worst-case and average-case time complexity is **O(n²)**.
- Performs many shifts when the array is in reverse order.

---

## Characteristics

- **Sorting Technique:** Comparison Sort
- **Stable:** ✅ Yes
- **In-Place:** ✅ Yes
- **Adaptive:** ✅ Yes
- **Recursive:** ❌ No

---

## Applications

- Sorting small arrays.
- Nearly sorted datasets.
- Used inside advanced sorting algorithms for small partitions.
- Online sorting where data arrives one element at a time.
- Educational purposes to understand sorting concepts.

---

## Example

### Input

```
12 54 23 9 4 15
```

### Output

```
4 9 12 15 23 54
```

---

## Conclusion

Insertion Sort is one of the simplest comparison-based sorting algorithms. It builds the sorted array one element at a time by inserting each new element into its correct position. Although it is not efficient for large datasets due to its **O(n²)** time complexity, it performs exceptionally well on small or nearly sorted arrays and is widely used for educational purposes and as a helper algorithm in more advanced sorting techniques.