#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(4);
    v.push_back(6);
    v.push_back(8);
    cout<<"finding 6 = "<<binary_search(v.begin(),v.end(),6)<<endl;
    cout<<"finding 6 lower bound = "<<lower_bound(v.begin(),v.end(),6)-v.begin()<<endl;
    int a = 3;
    int b = 5;
    cout<<"max -> "<<max(a,b)<<endl;
    cout<<"min -> "<<min(a,b)<<endl;
    swap(a,b);
    cout<<"swapping -> "<<a<<" "<<b<<endl;
    string abcd = "abcd";
    reverse(abcd.begin(),abcd.end());
    cout<<"Reversed = "<<a<<endl;
    sort(v.begin(),v.end());
    
}