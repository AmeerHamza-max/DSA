# 2D Arrays in C++ — Complete Guide

## 1. What Is a 2D Array?

A 2D array is a **collection of elements arranged in rows and columns** — think of it like a spreadsheet or a chessboard. Each element is accessed using two indices: one for the row, one for the column.

```
Row 0:  [1]  [2]  [3]  [4]
Row 1:  [5]  [6]  [7]  [8]
Row 2:  [9]  [10] [11] [12]
```

**Real-world analogy:** Imagine a hostel with rooms arranged in a grid — Building A has 3 floors, and each floor has 4 rooms. To find a specific room, you need two pieces of information: the floor number and the room number on that floor. That's exactly how a 2D array works — `arr[floor][room]`.

A 1D array is like a single hallway of rooms. A 2D array is like a whole building.

---

## 2. Declaration Syntax

```cpp
int arr[3][4];  // 3 rows, 4 columns → 12 total elements
```

You can also declare and initialize at the same time:

```cpp
int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

// Or more readably, row by row:
int arr[3][4] = {
    {1, 11, 111, 1111},
    {2, 22, 222, 2222},
    {3, 33, 333, 3333}
};
```

**Rule:** You can omit the **row size** during initialization (the compiler counts rows for you), but you can **never** omit the column size — more on why in Section 5.

```cpp
int arr[][4] = {{1,2,3,4},{5,6,7,8}};  // valid — 2 rows inferred
int arr[3][]  = {{1,2,3,4},{5,6,7,8}}; // ❌ invalid — column size required
```

---

## 3. How 2D Arrays Are Stored in Memory

This is the part most people memorize without truly understanding — so let's build it from scratch.

### The core truth: **Memory is linear (1D), not a grid**

Your computer's RAM is just one long strip of numbered boxes (addresses). There is no such thing as "2D memory." So when you create `int arr[3][4]`, the compiler doesn't build a grid — it **flattens** the 12 elements into one continuous block of 12 boxes, and *pretends* it's a grid for your convenience.

```
Logical view (how you think about it):
arr[0][0] arr[0][1] arr[0][2] arr[0][3]
arr[1][0] arr[1][1] arr[1][2] arr[1][3]
arr[2][0] arr[2][1] arr[2][2] arr[2][3]

Actual memory (how it's really stored) — Row-Major Order:
arr[0][0] arr[0][1] arr[0][2] arr[0][3] arr[1][0] arr[1][1] arr[1][2] arr[1][3] arr[2][0] arr[2][1] arr[2][2] arr[2][3]
```

C++ uses **Row-Major Order**: it stores the *entire first row*, then the *entire second row*, and so on. (Some languages like Fortran use Column-Major Order instead — they store column by column.)

### The Address Formula

If `arr` starts at base address `B`, and each `int` takes `4` bytes, then:

```
Address of arr[i][j] = B + (i * total_columns + j) * size_of(int)
```

**Why this formula works:** To reach row `i`, you must first skip over `i` *complete rows*, each containing `total_columns` elements. Then, within your target row, you move `j` more steps to reach the correct column.

**Worked example:** For `arr[3][4]`, find the address of `arr[1][2]` if `B = 1000` and `int` = 4 bytes.

```
Address = 1000 + (1 * 4 + 2) * 4
        = 1000 + (4 + 2) * 4
        = 1000 + 6 * 4
        = 1000 + 24
        = 1024
```

This is exactly why `arr[i][j]` is really just syntactic sugar — under the hood, the compiler converts it into this flat-index arithmetic automatically. You never have to write the formula yourself, but knowing it demystifies *everything* else in this guide (especially Section 5).

---

## 4. Input and Output — The Standard Pattern

Since a 2D array is a "grid," you almost always use **nested loops**: outer loop for rows, inner loop for columns.

### Taking Input

```cpp
int arr[3][4];
for (int i = 0; i < 3; i++) {        // outer loop → walks through rows
    for (int j = 0; j < 4; j++) {    // inner loop → walks through columns in that row
        cin >> arr[i][j];
    }
}
```

**Mental model:** For each row, visit every column before moving to the next row — exactly matching how it's stored in memory (Section 3). This is why row-major traversal is also the *cache-friendliest* way to loop through a 2D array.

### Printing Output

```cpp
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
        cout << arr[i][j] << " ";
    }
    cout << endl;   // move to next line after finishing a row
}
```

The `cout << endl` sits **outside the inner loop, inside the outer loop** — that's the detail beginners often get backwards, which causes the whole grid to print on one line.

---

## 5. Why You Must Specify the Column Size in Function Parameters

This is one of the most commonly memorized-but-not-understood rules in C++, so let's derive it instead of just stating it.

```cpp
void printArray(int arr[][4], int rows, int cols) {  // ✅ column size (4) required
    ...
}

void printArray(int arr[][], int rows, int cols) {   // ❌ compiler error
    ...
}
```

**The reasoning, step by step:**

1. From Section 3, we know `arr[i][j]` is really computed as `B + (i * total_columns + j) * size`.
2. To compute *any* element's address, the compiler **must know `total_columns`** — it's baked directly into the arithmetic.
3. When you pass an array to a function, C++ doesn't copy the whole array — it **decays it into a pointer** to its first element (specifically, a pointer to an array of `int`, of type `int(*)[4]`).
4. For the compiler to generate correct pointer arithmetic inside the function (i.e., to know how many bytes to "jump" to get from `arr[i]` to `arr[i+1]`), it needs to know the size of one row — which is `total_columns * size_of(element)`.
5. The **row size is irrelevant** to this calculation — that's *only* used to know how many rows exist, which you can pass separately as a normal `int` parameter. But column size is structurally required to interpret memory correctly.

**Analogy:** Imagine giving someone directions using only "walk forward 6 steps" without telling them how many steps make up one "row" of a building. They can't know if that lands them on the next room in the same hallway or wanders into a totally different floor. The column count is the "steps per row" — without it, address math breaks.

**Ways to pass a 2D array as a parameter:**

```cpp
void func(int arr[][4], int rows);   // most common — column size fixed
void func(int (*arr)[4], int rows);  // equivalent — arr is a pointer to an array of 4 ints
void func(int **arr);                // ❌ NOT the same — only works for arrays of pointers (like dynamically allocated jagged arrays), not a true static 2D array
```

---

## 6. Common Mistakes and Edge Cases

| Mistake | Why It's Wrong | Fix |
|---|---|---|
| `if (arr[row][col] -= target)` | `-=` is an assignment operator, not a comparison. This **modifies** the array and almost always evaluates truthy (unless result is 0). | Use `==` for comparison. |
| Forgetting column size in function signature | Compiler can't compute row stride (Section 5). | Always write `arr[][N]` or `(*arr)[N]`. |
| Swapping row/column loop bounds | E.g., looping `col < rows` instead of `col < cols` — silently reads garbage or crashes for non-square arrays. | Double check which bound goes with which loop variable, especially for non-square (rows ≠ cols) arrays. |
| Declaring `int arr[3][4]` but looping to `<= 3` or `<= 4` | Off-by-one — valid indices are `0` to `size-1`. | Always use `<`, never `<=`, with the exact declared size. |
| Assuming 2D arrays are "arrays of arrays" (pointer-of-pointers) at the language level | A static 2D array is one **contiguous** memory block, not scattered rows linked by pointers (that's only true for dynamically allocated jagged arrays via `new`). | Understand row-major flattening (Section 3). |
| Reusing loop variable names in inner functions (shadowing) | E.g., declaring `int row` as both a parameter and a loop variable inside the same function — the inner one silently shadows the outer, causing confusing bugs. | Use distinct variable names, or avoid re-declaring parameters as loop counters. |

---

## 7. Time Complexity Reference

| Operation | Complexity | Why |
|---|---|---|
| Access `arr[i][j]` | O(1) | Direct address computation (Section 3) — no traversal needed. |
| Full traversal (sum, print, search) | O(rows × cols) | Must visit every element once. |
| Row-wise sum | O(rows × cols) | Same — every element touched exactly once. |
| Binary search (only if array is sorted when flattened row-major) | O(log(rows × cols)) | Treats the grid as a virtual 1D sorted array — see Section 8. |
| Spiral / wave traversal | O(rows × cols) | Still visits each element exactly once, just in a different order. |

---

## 8. Applying the Concepts — Walking Through Your Code

Your uploaded file implements several classic 2D array patterns. Here's what each one demonstrates:

### `rowWiseSum` — Basic Traversal
Straightforward nested loop: outer loop fixes a row, inner loop accumulates that row's total. Textbook O(rows × cols) traversal.

### `largestRowSum` — Traversal + Tracking a Maximum
Same traversal pattern as above, but keeps a running `maxi` and `rowIndex` — a common "find the best X" pattern you'll reuse constantly (max subarray, best row, best path, etc.).

### `wavePrint` — Direction-Switching Traversal
Iterates **column by column** (not row by row!), alternating direction using `col & 1` (a bitwise trick to check odd/even — cleaner than `col % 2`). This shows that traversal order isn't fixed — you choose the pattern based on the problem.

### `binarySearch` on a 2D grid — Treating 2D as Flattened 1D
This is a great real application of Section 3's address formula, reversed:

```cpp
int element = arr[mid / cols][mid % cols];
```

Instead of converting `(row, col) → flat index` (like the address formula does), this converts `flat index → (row, col)`:
- `mid / cols` → which row the flat index falls into
- `mid % cols` → the position within that row

This only works correctly if the grid is sorted as if it were one long row-major sequence.

### `spiralPrint` — Boundary-Shrinking Traversal
Uses four shrinking boundaries (`top`, `bottom`, `left`, `right`) and peels the grid like an onion — print the top row, right column, bottom row, left column, then shrink all four boundaries inward and repeat. A very common interview pattern.

---

## 9. Quick-Reference Cheat Sheet

```cpp
// Declare
int arr[ROWS][COLS];

// Input
for (int i = 0; i < ROWS; i++)
    for (int j = 0; j < COLS; j++)
        cin >> arr[i][j];

// Output
for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++)
        cout << arr[i][j] << " ";
    cout << endl;
}

// Pass to function — column size is MANDATORY
void func(int arr[][COLS], int rows);

// Address formula (mental model only — compiler does this for you)
// address = base + (i * COLS + j) * sizeof(int)
```

---

## A Quick Note on Your Uploaded Code

While reading through your file, one line stood out — in `isPresent`:

```cpp
if(arr[row][col]-=target){   // this ASSIGNS (target subtracted from element), not compares
```

This should be `==` for comparison:

```cpp
if(arr[row][col] == target){
    return 1;
}
```

As written, `-=` overwrites the array's values as a side effect and returns the new value (truthy unless it's exactly `0`), so the search logic won't behave as intended. This is a classic "single-character bug" — `=` vs `==` vs `-=` — worth training your eye to catch since it compiles cleanly but silently breaks logic.
