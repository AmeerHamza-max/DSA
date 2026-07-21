# Bubble Sort in C++

## Overview

This program implements the **Bubble Sort** algorithm in C++ using a `vector`. Bubble Sort repeatedly compares adjacent elements and swaps them if they are in the wrong order. After each pass, the largest unsorted element "bubbles up" to its correct position.

This implementation also includes an **optimization** using a `swapped` flag, which stops the algorithm early if the array is already sorted.

---

## Problem Statement

Given an unsorted array of integers:

```cpp
{6, 2, 8, 4, 10}
```

Sort the array in **ascending order** using the **Bubble Sort** algorithm.

---

## Source Code

```cpp
#include<iostream>
using namespace std;
#include<vector>

int main() {
    vector<int> arr = {6, 2, 8, 4, 10};
    int n = 5;

    bool swapped = false;

    for(int i = 0; i < n; i++) {

        swapped = false;

        for(int j = 0; j < n - i - 1; j++) {

            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if(swapped == false) {
            break;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
```

---

## Note

Your original code contains two small issues:

### 1. Inner Loop Condition

You wrote:

```cpp
for(int j = 0; j < n - i; j++)
```

This accesses `arr[j + 1]`, which causes an **out-of-bounds** error when `j = n - i - 1`.

Correct version:

```cpp
for(int j = 0; j < n - i - 1; j++)
```

---

### 2. Reset the `swapped` Flag

The `swapped` variable should be reset at the beginning of every pass.

Correct:

```cpp
swapped = false;
```

inside the outer loop.

---

## Algorithm

1. Start from the beginning of the array.
2. Compare every pair of adjacent elements.
3. Swap them if they are in the wrong order.
4. After each pass, the largest element reaches its correct position.
5. Repeat until the array becomes sorted.
6. If no swaps occur during a pass, stop early because the array is already sorted.

---

## Dry Run

### Initial Array

```
6 2 8 4 10
```

---

### Pass 1

Compare:

```
6 and 2 → Swap
```

Array:

```
2 6 8 4 10
```

Compare:

```
6 and 8 → No Swap
```

Compare:

```
8 and 4 → Swap
```

Array:

```
2 6 4 8 10
```

Compare:

```
8 and 10 → No Swap
```

Result after Pass 1:

```
2 6 4 8 10
```

---

### Pass 2

Compare:

```
2 and 6 → No Swap
```

Compare:

```
6 and 4 → Swap
```

Array:

```
2 4 6 8 10
```

Compare:

```
6 and 8 → No Swap
```

Result after Pass 2:

```
2 4 6 8 10
```

---

### Pass 3

No swaps occur.

The algorithm stops early because the array is already sorted.

---

## Output

```
2 4 6 8 10
```

---

## How Bubble Sort Works

Initial array:

```
6 2 8 4 10
```

### Pass 1

```
6 2 8 4 10
↓
2 6 8 4 10
↓
2 6 4 8 10
```

Largest element:

```
10
```

is already at the end.

---

### Pass 2

```
2 6 4 8 10
↓
2 4 6 8 10
```

---

### Pass 3

No swaps.

Algorithm terminates.

Final array:

```
2 4 6 8 10
```

---

## Time Complexity

| Case | Complexity |
|------|------------|
| Best Case | **O(n)** |
| Average Case | **O(n²)** |
| Worst Case | **O(n²)** |

### Explanation

- **Best Case:** The array is already sorted, so only one pass is required due to the `swapped` optimization.
- **Average Case:** Multiple comparisons and swaps are required.
- **Worst Case:** The array is in reverse order, requiring the maximum number of comparisons and swaps.

---

## Space Complexity

| Complexity |
|------------|
| **O(1)** |

Bubble Sort is an **in-place sorting algorithm** because it requires only a constant amount of additional memory.

---

## Advantages

- Very simple to understand.
- Easy to implement.
- In-place sorting algorithm.
- Stable sorting algorithm.
- Optimized version performs well on already sorted arrays.
- Useful for learning sorting algorithms.

---

## Disadvantages

- Slow for large datasets.
- High time complexity of **O(n²)**.
- Performs many unnecessary comparisons.
- Not suitable for real-world large-scale applications.

---

## Characteristics

- **Sorting Technique:** Comparison Sort
- **Stable:** ✅ Yes
- **In-Place:** ✅ Yes
- **Adaptive:** ✅ Yes (with swapped optimization)
- **Recursive:** ❌ No

---

## Applications

- Educational purposes.
- Small datasets.
- Detecting whether an array is already sorted.
- Situations where simplicity is more important than efficiency.

---

## Example

### Input

```
6 2 8 4 10
```

### Output

```
2 4 6 8 10
```

---

## Conclusion

Bubble Sort is one of the simplest sorting algorithms. It repeatedly compares adjacent elements and swaps them until the array is sorted. Although its average and worst-case time complexity is **O(n²)**, the optimized version using a `swapped` flag can terminate early when the array is already sorted, making it efficient for nearly sorted datasets. Bubble Sort is mainly used for educational purposes because of its simplicity.