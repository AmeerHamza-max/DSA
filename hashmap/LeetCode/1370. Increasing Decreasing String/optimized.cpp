#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:
    string sortString(string s) {

        vector<int> freq(26, 0);

        // Count frequency
        for(char ch : s){
            freq[ch - 'a']++;
        }

        string ans = "";

        while(ans.length() < s.length()){

            // Increasing order
            for(int i = 0; i < 26; i++){
                if(freq[i] > 0){
                    ans += char(i + 'a');
                    freq[i]--;
                }
            }

            // Decreasing order
            for(int i = 25; i >= 0; i--){
                if(freq[i] > 0){
                    ans += char(i + 'a');
                    freq[i]--;
                }
            }
        }

        return ans;
    }
};