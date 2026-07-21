#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int current = 0;
        int highest = 0;

        for (int g : gain) {
            current += g;
            highest = max(highest, current);
        }

        return highest;
    }
};