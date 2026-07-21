// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;


int main() {
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(4);
    int target = 6;
    vector<int> ans;
    for(int i = 0 ; i < nums.size()-1;i++){
        for(int j = i+1 ; j < nums.size();j++){
            if(nums[i]+nums[j]==target){
                ans.push_back(i);
                ans.push_back(j);
                
            }
        }
        
    }
    for(int i = 0 ; i < ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}