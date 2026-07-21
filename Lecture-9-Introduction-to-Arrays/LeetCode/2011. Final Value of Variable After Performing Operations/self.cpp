#include <iostream>
using namespace std;
#include<vector>
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0;
        for(auto op:operations){
            if(op=="--X"){
            --x;
       }
       else if (op=="X++"){
           x++;
       }
       else if(op=="++X"){
           ++x;
       }
       else{
           x--;
       }
       
        }
        return x;
    }
};