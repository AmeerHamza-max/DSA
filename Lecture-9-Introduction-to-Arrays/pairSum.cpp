#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int sum=5;
    int arr[5]={1,2,3,4,5};
    vector<vector <int>> ans;
    int n = sizeof(arr)/sizeof(int);
    for(int i = 0; i < n ; i++){
        for(int j = i+1;j<n;j++){
            if(arr[i]+arr[j]==sum){
               vector<int> temp;
               temp.push_back(min(arr[i],arr[j]));
               temp.push_back(max(arr[i],arr[j]));
               ans.push_back(temp);
            }

        }
    }
    sort(ans.begin(),ans.end());
   for(int i = 0; i < ans.size(); i++) {
    cout << "[ ";

    for(int j = 0; j < ans[i].size(); j++) {
        cout << ans[i][j] << " ";
    }

    cout << "]" << endl;
}
    

    
    
}