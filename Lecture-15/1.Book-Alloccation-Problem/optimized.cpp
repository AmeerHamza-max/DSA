#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Check if it is possible to allocate books
bool isPossible(vector<int> arr, int n, int m, int mid) {
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < n; i++) {
        if (pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        } else {
            studentCount++;

            if (studentCount > m || arr[i] > mid) {
                return false;
            }

            pageSum = arr[i];
        }
    }

    return true;
}

// Find minimum possible maximum pages
int allocateBooks(vector<int> arr, int n, int m) {

    // More students than books
    if (m > n)
        return -1;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    int s = *max_element(arr.begin(), arr.end());
    int e = sum;
    int ans = -1;

    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }

    return ans;
}

int main() {

    int n, m;

    cout << "Enter number of books: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter pages in each book:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter number of students: ";
    cin >> m;

    int result = allocateBooks(arr, n, m);

    if (result == -1)
        cout << "Allocation is not possible." << endl;
    else
        cout << "Minimum possible maximum pages = " << result << endl;

    return 0;
}