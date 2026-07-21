// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include<vector>
int main() {
     
        vector<int> nums={2,5,1,3,4,7};
        int n =3;
        vector<int> ans;
        for(int i = 0 ; i < n ; i++){
            ans.push_back(nums[i]);
            ans.push_back(nums[i+n]);
        }
        for(int i = 0 ; i < ans.size();i++){
            cout<<ans[i]<<" ";
        }
    


    return 0;
}