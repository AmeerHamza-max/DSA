# LeetCode 2570: Merge Two 2D Arrays by Summing Values

This repository contains the C++ solution for LeetCode Problem **2570. Merge Two 2D Arrays by Summing Values**.

## 📝 Problem Statement

You are given two 2D integer arrays `nums1` and `nums2`.
* `nums1[i] = [id_i, val_i]` indicates that the number with the ID `id_i` has a value equal to `val_i`.
* `nums2[i] = [id_i, val_i]` indicates that the number with the ID `id_i` has a value equal to `val_i`.

Both arrays contain unique IDs and are sorted in ascending order by ID.

Merge the two arrays into one array sorted in ascending order by ID, following these rules:
1. Only IDs that appear in at least one of the two arrays should be included.
2. Each ID should be included only once, with its value equal to the sum of the values of this ID in both arrays (if missing in one, assume value is 0).

---

## 💡 Solution Approach (Two Pointers)

Since both input arrays are already **sorted by ID**, we use the **Two Pointers Technique** (similar to the merge step of Merge Sort) to solve this efficiently without extra sorting steps:

1. Maintain pointer `i` for `nums1` and pointer `j` for `nums2`.
2. Compare `id` at `nums1[i]` and `nums2[j]`:
   - **Equal IDs:** Add the summed values `[id, val1 + val2]` to the result, then increment both `i` and `j`.
   - **`nums1[i]` ID is smaller:** Push `nums1[i]` to the result and increment `i`.
   - **`nums2[j]` ID is smaller:** Push `nums2[j]` to the result and increment `j`.
3. Append any remaining elements from either array after the main loop finishes.

### Complexity
- **Time Complexity:** $O(N + M)$ — Single pass over both input arrays.
- **Space Complexity:** $O(1)$ extra auxiliary space (excluding the output vector).

---

## ⚙️ How to Run in VS Code

### Prerequisites
- GCC/G++ Compiler installed (e.g., via MinGW on Windows or GCC on Linux/macOS).
- VS Code with the **C/C++ Extension** installed.

### Steps
1. Clone or download this repository.
2. Open the project folder in VS Code.
3. Open `main.cpp`.
4. Compile and run using the terminal:

```bash
# Build the executable
g++ -std=c++17 main.cpp -o main

# Run the executable
./main      # Linux/macOS
main.exe    # Windows