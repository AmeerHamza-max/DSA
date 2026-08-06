#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {

        queue<int> q;

        // Queue mein students daal do
        for (int x : students) {
            q.push(x);
        }

        int i = 0;          // sandwich index
        int count = 0;      // consecutive students jo sandwich nahi le paaye

        while (!q.empty() && count < q.size()) {

            if (q.front() == sandwiches[i]) {
                q.pop();      // student chala gaya
                i++;          // next sandwich
                count = 0;    // reset
            }
            else {
                int temp = q.front();
                q.pop();
                q.push(temp);
                count++;
            }
        }

        return q.size();
    }
};