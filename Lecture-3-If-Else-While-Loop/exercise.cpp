#include<iostream>
using namespace std;
int main (){
    char ch;
    cout<<"Enter a Character = ";
    cin >> ch;
    if(ch >= 'a' && ch <='z'){
        cout<<"This is lowercase";
    }
    else if (ch >='A' && ch<='Z'){
        cout<<"This is uppercase letter";
    }
    else if(ch >='0' && ch<='9'){
        cout<<"This is a number";
    }
    else{
        cout<<"Invalid character";
    }

}