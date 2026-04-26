#include<iostream>
using namespace std;
int main(){
    int a = 4;
    int b = 6;
    cout<<"a&b = "<<(a&b)<<endl;
    cout<<"a|b = "<<(a|b)<<endl;
    cout<<"~a = "<<(~a)<<endl;
    cout<<"a^b = "<<(a^b)<<endl;

    cout<<"17 >> 1 = "<<(17 >> 1)<<endl;
    cout<<"17 >> 2 = "<<(17 >> 2)<<endl;
    cout<<"19 << 1 = "<<(19 << 1)<<endl;
    cout<<"21 << 2 = "<<(21 << 2)<<endl;


    int i = 7;
    cout<<(++i)<<endl;
    cout<<(i++)<<endl;
    cout<<(i--)<<endl;
    cout<<(--i)<<endl;

    int a1,b1=1;
    a1=10;
    if(++a){
        cout<<b1<<endl;
    }
    else{
        cout<<++b1;
    }
    a1=1;
    b1=2;
    if(a1-- > 0 && ++b > 2){
        cout<<"Stage1 - Inside If";
    }
    else{
        cout<<"Stage 2 - Inside else";
    }
}