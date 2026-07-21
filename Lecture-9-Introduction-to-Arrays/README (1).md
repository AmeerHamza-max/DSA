# C++ Arrays — Complete Guide

## Table of Contents
1. [What is an Array?](#what-is-an-array)
2. [Why Do We Need Arrays?](#why-do-we-need-arrays)
3. [Memory Layout](#memory-layout)
4. [Declaration](#declaration)
5. [Initialization](#initialization)
6. [Accessing Elements](#accessing-elements)
7. [Taking Input in an Array](#taking-input-in-an-array)
8. [sizeof() Trick](#sizeof-trick)
9. [Arrays and Functions (Pass by Reference)](#arrays-and-functions-pass-by-reference)
10. [Garbage Values & Out-of-Bounds](#garbage-values--out-of-bounds)
11. [Array Types](#array-types)
12. [Common Array Algorithms](#common-array-algorithms)
    - [Calculate Sum](#1-calculate-sum)
    - [Linear Search](#2-linear-search)
    - [Find Max & Min](#3-find-max--min)
    - [Reverse an Array](#4-reverse-an-array)
    - [Update via Function (Pass by Reference Demo)](#5-update-via-function-pass-by-reference-demo)
13. [Common Mistakes](#common-mistakes)
14. [Quick Reference Cheat Sheet](#quick-reference-cheat-sheet)

---

## What is an Array?

An **array** is a collection of elements that share:

1. **Same data type** — all elements must be of the same type (all `int`, all `char`, all `double`, etc.)
2. **Contiguous memory locations** — elements are stored one after another in memory with no gaps
3. **Index-based access** — every element can be accessed using its index (position number)

Without arrays, storing 1000 values would require 1000 separate variables:

```cpp
int a = 2, b = 3, c = 0; // fine for 3 values
// but what about 1000 values? Impossible to manage!
```

With an array:

```cpp
int dost[1000]; // stores 1000 integers with one line
```

---

## Why Do We Need Arrays?

- Store **multiple values of the same type** under a single name
- Process values using **loops** instead of writing repetitive code
- Pass a large collection of values to a **function** efficiently
- Implement almost every important algorithm (search, sort, reverse, etc.)

---

## Memory Layout

When you declare `int dost[7]`, the computer allocates 7 × 4 = **28 bytes** of contiguous memory:

```
Index:    [0]   [1]   [2]   [3]   [4]   [5]   [6]
Value:     12    13    14    15    16    17    18
Address:  100   104   108   112   116   120   124
```

### Address Formula

```
Address of element = base_address + index × size_of_datatype
```

Example: `dost[3]` → `100 + 3 × 4 = 112`

| Datatype | Size (bytes) |
|----------|-------------|
| `int`    | 4           |
| `char`   | 1           |
| `float`  | 4           |
| `double` | 8           |
| `bool`   | 1           |

---

## Declaration

```cpp
// Syntax: datatype name[size];
int   number[10];       // array of 10 integers
char  ch[5];            // array of 5 characters
float prices[100];      // array of 100 floats
double values[50];      // array of 50 doubles
bool  flags[20];        // array of 20 booleans
```

> **Important:** Index runs from **0** to **n−1**. An array of size 10 has valid indices 0 through 9.

---

## Initialization

### 1. Initialize with specific values

```cpp
int number[3] = {5, 7, 11};
// number[0]=5, number[1]=7, number[2]=11
```

### 2. Partial initialization (rest filled with 0)

```cpp
int third[15] = {2, 7};
// third[0]=2, third[1]=7, third[2..14]=0
```

### 3. Initialize entire array to 0

```cpp
int fourth[10] = {0};
// All 10 elements are 0
```

> **Note:** `{0}` sets the first element to 0 and C++ automatically fills the rest with 0 as well. However, `{1}` sets ONLY the first element to 1; the rest are still 0, NOT 1.

```cpp
int fifth[10] = {1};
// fifth[0]=1, fifth[1..9]=0   ← common mistake!
```

### 4. Let the compiler figure out the size

```cpp
int arr[] = {2, 7, 1, -4, 11};
// Size is automatically 5
```

### 5. Character arrays

```cpp
char ch[5] = {'a', 'b', 'c', 'd', 'e'};
```

---

## Accessing Elements

```cpp
int arr[5] = {2, 7, 1, -4, 11};

arr[0]  // → 2   (first element)
arr[1]  // → 7
arr[4]  // → 11  (last element, index = size-1)
```

### Traversal using a for loop

```cpp
int n = 5;
for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
}
// Output: 2 7 1 -4 11
```

---

## Taking Input in an Array

```cpp
int size;
cin >> size;

int num[size]; // Variable-Length Array (VLA) — works in GCC

for (int i = 0; i < size; i++) {
    cin >> num[i];
}
```

---

## sizeof() Trick

When you don't want to hardcode the size, use `sizeof`:

```cpp
int arr[5] = {2, 7, 1, -4, 11};
int size = sizeof(arr) / sizeof(int);
// sizeof(arr) = 20 bytes (5 × 4)
// sizeof(int) = 4 bytes
// size = 20 / 4 = 5 ✓
```

For `char` arrays:
```cpp
char ch[5] = {'a','b','c','d','e'};
int size = sizeof(ch) / sizeof(char); // = 5
```

> **Warning:** This trick **only works in the same scope** where the array is declared. Inside a function that receives `arr[]` as a parameter, `sizeof(arr)` gives the pointer size (8 bytes on 64-bit), NOT the array size. Always pass `size` as a separate parameter.

---

## Arrays and Functions (Pass by Reference)

Unlike regular variables (which are **passed by value**), arrays are **always passed by reference** — meaning the function receives the **memory address** of the array, not a copy.

```cpp
void update(int arr[], int n) {
    arr[0] = 120; // This changes the ORIGINAL array in main!
}

int main() {
    int arr[3] = {1, 2, 3};
    update(arr, 3);
    // arr[0] is now 120, not 1
}
```

**Why?** When you write `update(arr, 3)`, you're passing the base address of `arr`. The function works directly on that memory location.

**Consequence:** Any modification inside the function **permanently changes** the original array.

---

## Garbage Values & Out-of-Bounds

### Uninitialized arrays contain garbage values

```cpp
int number[15];
cout << number[0]; // prints some random garbage value
```

### Accessing out-of-bounds index is undefined behavior

```cpp
int number[15];
cout << number[25]; // dangerous! may print garbage or crash
```

C++ does **not** throw an error for out-of-bounds — it just reads/writes whatever memory happens to be there (undefined behavior).

---

## Array Types

### Integer Array
```cpp
int arr[5] = {1, 2, 3, 4, 5};
```

### Character Array
```cpp
char ch[5] = {'a', 'b', 'c', 'd', 'e'};
```

### Float / Double Array
```cpp
float prices[3] = {9.99, 14.5, 3.0};
double data[3]  = {1.1, 2.2, 3.3};
```

### Boolean Array
```cpp
bool flags[3] = {true, false, true};
```

---

## Common Array Algorithms

### 1. Calculate Sum

```cpp
#include <iostream>
using namespace std;

int calculateSum() {
    int arr[5] = {2, 7, 1, -4, 11};
    int size = sizeof(arr) / sizeof(int);
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    cout << "Sum = " << calculateSum() << endl; // Output: 17
}
```

**How it works:** Start with `sum = 0`, then add each element one by one using a loop.

---

### 2. Linear Search

Search for a target value by checking every element one by one.

```cpp
#include <iostream>
using namespace std;

bool linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return true;  // found
        }
    }
    return false; // not found
}

int main() {
    int arr[10] = {5, 7, -2, 10, -2, 0, 5, 22, 2};
    int size = sizeof(arr) / sizeof(int);
    int target = 1;

    if (linearSearch(arr, size, target)) {
        cout << "Target Found" << endl;
    } else {
        cout << "Target not found" << endl;
    }
}
```

**Time Complexity:** O(n) — in the worst case, checks all n elements.

---

### 3. Find Max & Min

```cpp
#include <iostream>
#include <climits>  // for INT_MIN and INT_MAX
using namespace std;

int getMax(int num[], int n) {
    int maxi = INT_MIN; // start with smallest possible int
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, num[i]);
    }
    return maxi;
}

int getMin(int num[], int n) {
    int mini = INT_MAX; // start with largest possible int
    for (int i = 0; i < n; i++) {
        if (num[i] < mini) {
            mini = num[i];
        }
    }
    return mini;
}

int main() {
    int size;
    cin >> size;
    int num[size];
    for (int i = 0; i < size; i++) {
        cin >> num[i];
    }
    cout << "Maximum: " << getMax(num, size) << endl;
    cout << "Minimum: " << getMin(num, size) << endl;
}
```

**Key constants from `<climits>`:**

| Constant  | Value                  | Use                        |
|-----------|------------------------|----------------------------|
| `INT_MIN` | −2,147,483,648         | Initial value for finding max |
| `INT_MAX` | +2,147,483,647         | Initial value for finding min |

---

### 4. Reverse an Array

Uses the **two-pointer technique**: one pointer at the start, one at the end, swap and move inward.

```cpp
#include <iostream>
#include <utility>  // for swap
using namespace std;

void reverse(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    while (start <= end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[4] = {2, 7, 5, 9};
    int size = sizeof(arr) / sizeof(int);

    cout << "Original: ";
    printArray(arr, size);

    reverse(arr, size);

    cout << "Reversed: ";
    printArray(arr, size);
    // Output: 9 5 7 2
}
```

**Visual:**
```
Step 0:  [2]  7   5  [9]   → swap → [9]  7   5  [2]
Step 1:   9  [7] [5]  2    → swap →  9  [5] [7]  2
Done:     9   5   7   2
```

---

### 5. Update via Function (Pass by Reference Demo)

```cpp
#include <iostream>
using namespace std;

void update(int arr[], int n) {
    cout << "Inside function:" << endl;
    arr[0] = 120; // modifies the original!
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[3] = {1, 2, 3};
    update(arr, 3);

    cout << "Back in main:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << arr[i] << " "; // prints: 120 2 3
    }
}
```

**Output:**
```
Inside function:
120 2 3
Back in main:
120 2 3
```

The change made inside the function **persists** in `main` because arrays pass their address, not a copy.

---

## Common Mistakes

| Mistake | Problem | Fix |
|--------|---------|-----|
| `int arr[5] = {1}` | Only first element is 1, rest are 0 | Use `{0}` for all zeros; loop for other values |
| `arr[5]` on size-5 array | Out of bounds (valid: 0–4) | Always use `i < size`, not `i <= size` |
| `sizeof(arr)/sizeof(int)` inside function | Returns pointer size, not array size | Always pass `size` as a parameter |
| Forgetting to pass `size` | Function doesn't know where the array ends | Always pair array with its size |
| Assuming `{1}` fills all with 1 | Only first element is 1 | Use a loop: `for(int i=0;i<n;i++) arr[i]=1;` |

---

## Quick Reference Cheat Sheet

```cpp
// Declaration
int arr[10];

// Initialization
int arr[3] = {5, 7, 11};   // specific values
int arr[10] = {0};          // all zeros
int arr[] = {1, 2, 3};     // compiler infers size = 3

// Get size (only in same scope as declaration)
int size = sizeof(arr) / sizeof(int);

// Access
arr[0]      // first element
arr[n-1]    // last element

// Loop through
for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
}

// Pass to function (always pass size too!)
void myFunc(int arr[], int size) { ... }
myFunc(arr, size);

// Useful constants
#include <climits>
INT_MIN   // smallest int  → use as initial max
INT_MAX   // largest int   → use as initial min

// Swap two elements
#include <utility>
swap(arr[i], arr[j]);
```
