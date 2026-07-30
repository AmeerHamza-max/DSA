// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include<vector>
#include<utility>
int main() {
   vector<int> nums;
   nums.push_back(3);
   nums.push_back(1);
   nums.push_back(2);
   nums.push_back(4);
   int left = 0 ;
   int right = nums.size()-1;
   while(left < right){
       if(nums[left] % 2 == 0){
           left++;
       }
       else if(nums[right] % 2 != 0){
           right--;
       }
       else{
           swap(nums[left],nums[right]);
           right--;
           left++;
       }
   }
   for(int num:nums){
       cout<<num<<" ";
   }
   cout<<endl;
  
    return 0;
}