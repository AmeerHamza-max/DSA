#include<iostream>
using namespace std;
int main(){
    int a = 123;
    // char a ='a'; give us an error that a is prviously defined
    cout<< a <<endl;
    char b = 'v';
    cout<< b <<endl;

    bool bl = true;
    cout<< bl << endl;

    float f = 1.2;
    cout << f << endl;

    double d = 1.23;
    cout << d << endl;
    int size = sizeof(a);
    cout<<"Size of a is :"<< sizeof(a) <<endl;
    cout<<"Size of b is :"<< sizeof(b) <<endl;
    cout<<"Size of bl is :"<< sizeof(bl) <<endl;
    cout<<"Size of f is :"<< sizeof(f) <<endl;
    cout<<"Size of d is :"<< sizeof(d) <<endl;

    char aa='bb';// we can't give dobule characters in single inverted commas

}