#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {

        vector<pair<int, string>> people;

        // Store (height, name)
        for (int i = 0; i < names.size(); i++) {
            people.push_back({heights[i], names[i]});
        }

        // Sort by height in descending order
        sort(people.begin(), people.end(), greater<pair<int, string>>());

        vector<string> ans;

        // Collect sorted names
        for (auto person : people) {
            ans.push_back(person.second);
        }

        return ans;
    }
};