#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {-4, -1, 0, 3, 10};

    int n = nums.size();
    vector<int> second(n);

    int left = 0;
    int right = n - 1;
    int index = n - 1;

    while (left <= right) {

        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];

        if (leftSquare > rightSquare) {
            second[index] = leftSquare;
            left++;
        }
        else {
            second[index] = rightSquare;
            right--;
        }

        index--;
    }

    for (int i = 0; i < second.size(); i++) {
        cout << second[i] << " ";
    }

    return 0;
}