// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include<string>
#include<vector>
using namespace std;

int main() {
    vector<char> s={'h','e','l','l','o'};
    int start = 0;
    int end = s.size()-1;
    while(start < end){
        swap(s[start],s[end]);
        start++;
        end--;
    }
    for(int i = 0 ; i < s.size();i++){
        cout<<s[i]<<" ";
    }
    
    return 0;
}