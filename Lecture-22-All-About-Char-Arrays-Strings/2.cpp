#include<iostream>
using namespace std;

char getMaxOccurCharacter(string s){
    int arr[26]={0};
    for(int i = 0; i < 26;i++){
        char ch = s[i];
        int number = 0;
        if(ch >= 'a' && ch <='z'){
            int n = ch - 'a';
        }
        else{
            number = ch - 'A';
        }
        arr[number]++;
    }
    int maxi = -1,ans=0;
    for(int i = 0 ; i < s.length();i++){
        if(maxi < arr[i]){
            ans = i;
            maxi=arr[i];
        }
    
    }
    char finalAns = 'a' + ans;
    return finalAns;
}


int main(){
    string s;
    cout<<"Enter a String ";
    cin>>s;
    cout<<"Getting maximum word count = "<<getMaxOccurCharacter(s)<<endl;
}