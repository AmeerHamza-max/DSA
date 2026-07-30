# Sort Array by Parity (Two-Pointer Approach) - C++

## 📌 Problem
Given an integer array, rearrange it so that all **even numbers** appear before all **odd numbers**.

The order of even or odd numbers does not matter.

## 💡 Approach
This solution uses the **Two-Pointer Algorithm**.

- Initialize:
  - `left` pointer at the beginning of the array.
  - `right` pointer at the end of the array.
- Move the `left` pointer forward while it points to an even number.
- Move the `right` pointer backward while it points to an odd number.
- If the left pointer is on an odd number and the right pointer is on an even number, swap them.
- Continue until both pointers meet.

## 🚀 Time Complexity

- **Time:** O(n)
- **Space:** O(1)

## 🛠️ Technologies Used

- C++
- STL Vector
- Two Pointer Technique

## 📂 Code

```cpp
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
    vector<int> nums;

    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(4);

    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {

        if (nums[left] % 2 == 0) {
            left++;
        }
        else if (nums[right] % 2 != 0) {
            right--;
        }
        else {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }

    for (int num : nums) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}
```

## 📥 Input

```text
3 1 2 4
```

## 📤 Output

```text
4 2 1 3
```

> The exact output may vary (e.g., `2 4 3 1`) because the relative order of even and odd elements is not preserved.

## 🧠 Key Concepts

- Two Pointer Technique
- Arrays
- Vectors
- Swapping Elements
- Time Complexity Optimization

## 📖 Learning Outcome

This project demonstrates how the two-pointer approach can partition an array efficiently in a single traversal without using extra memory.

## 👨‍💻 Author

**Ameer Hamza**