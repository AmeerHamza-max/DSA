// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include<string>
bool isVowel(char ch){
    return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'
    || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U');
}
int main() {
    string s = "IceCreAm";
    int left = 0; 
    int right = s.length()-1;
    while(left < right){
        while(left < right && !isVowel(s[left])){
            left++;
        }
        while(left < right && !isVowel(s[right])){
            right--;
        }
        swap(s[left],s[right]);
        left++;
        right--;
    }
    cout<<s<<endl;
    
    

    return 0;
}