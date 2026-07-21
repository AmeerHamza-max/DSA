#include <iostream>
using namespace std;
#include<vector>
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAltitude = 0;
        int curAltitude = 0;
        
        for (int i = 0; i < gain.size(); i++) {
            curAltitude += gain[i];
            maxAltitude = max(maxAltitude, curAltitude);
        }
        
        return maxAltitude;
    }
};