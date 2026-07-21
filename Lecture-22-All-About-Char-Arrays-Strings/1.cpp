#include<iostream>
using namespace std;
bool checkPalindrome(char a[], int n){
    int s = 0;
    int e = n - 1;
    while(s<=e){
        if(a[s] != a[e]){
            return 0;
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}
void reverse(char name[], int n ){
    int s = 0;
    int e = n-1;
    while(s<=e){
        swap(name[s++],name[e--]);
    }
}
int getLength(char name[]){
    int count = 0 ;
    for(int i = 0 ; name[i]!='\0';i++){
        count++;
    }
    return count;

}
char toLowerCase(char ch){
    if(ch>='a' && ch <='z'){
        return ch;
    }
    else{
        char temp = ch - 'A' + 'a';
        return temp;

    }
}
int main(){
    char name[20];
    cout<<"Enter your name = ";

    cin >> name;
    // name[2]='\0';
    cout<<"Your name is ";
    cout<<name<<endl;
    int len=getLength(name);

    cout<<"Length = "<<len<< endl;
    reverse(name,len);
    cout<<"Your name is ";
    cout<<name<<endl;
    cout<<"Checking Palindrome or not : "<<checkPalindrome(name,len)<<endl;
    cout<<"Character is "<<toLowerCase('a')<<endl;
    cout<<"Character is "<<toLowerCase('A')<<endl;


}