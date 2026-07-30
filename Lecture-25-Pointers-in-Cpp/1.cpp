#include<iostream>
using namespace std;
int main(){
    int num = 5;
    cout<<num<<endl;

    cout<<"Adress of num is "<<&num<<endl;

    int *ptr = &num;
    cout<<"Value id = "<<*ptr<<endl;

    cout<<"Address of *ptr = "<<ptr<<endl;

    double d = 4.3;
    double *p2=&d;
    cout<<"Address of ptr2 "<<*p2<<endl;
    cout<<"Size of integer is "<<sizeof(num)<<endl;
    cout<<"Size of Pointer is "<<sizeof(ptr)<<endl;
    cout<<"Size of Pointer is "<<sizeof(p2)<<endl;
    return 0;
}