// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include<vector>
#include<utility>
int main() {
   vector<int> nums;
   nums.push_back({4});
   nums.push_back({2});
   nums.push_back({5});
   nums.push_back({7});
   int evenIndex = 0 ;
   int oddIndex = 1;
   vector<int> nums1(nums.size());
   for(int i = 0 ; i < nums.size();i++){
       if(nums[i]%2==0){
         nums1[evenIndex]=nums[i];
         evenIndex+=2;
       }
       else{
           nums1[oddIndex]=nums[i];
           oddIndex+=2;
       }
   }
   for(const auto& num:nums1){
       cout<<num<<" ";
   }
    return 0;
}