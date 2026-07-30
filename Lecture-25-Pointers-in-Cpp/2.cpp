#include<iostream>
using namespace std;
int main(){
    // pointer to int is created and pointing to some garbage address
    // int *p;//this is bad practice;segmentation fault 
    int i = 5;
    int *p = 0;
    p = &i;
    cout<<p<<endl;
    cout<<*p<<endl;
    int *q = &i;
    cout<<q<<endl;
    cout<<*q<<endl;

    int num = 5;
    int a = num;
    a++;
    cout<<num<<endl;

    *p=num;
    cout<<*p<<endl;
    *p++;
    cout<<*p<<endl;
    // Copying a pointer
    int *s = p;
    cout<<p<<" ~ "<< s <<endl;
    cout<<*p<<" ~ "<<*s<<endl;
    int j = 3;
    int *t = &j;
    // It went to 4 bytes 
    t= t+ 1;
    cout<<*t++<<endl;

}