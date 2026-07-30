#include<iostream>
using namespace std;
void update (int **p){
    // p = p +1;
    // kuch change hoga ??
   
    // *p = *p + 1;
    // kuch change hoga

    **p = **p + 1;
    // kuch change ho ga 


}
int main(){
    int i = 5;
    int *p=&i;
    int **p2=&p;
    cout<<endl<<"Sab chal Raha ha "<<endl;
    cout<<"Printing P "<<p<<endl;
    cout<<"Address of p "<<&p<<endl;
    cout<<"Address of p2 "<<*p2<<endl;
    cout<<endl;
    cout<<endl;
    
    cout<<"I is "<<i<<endl;
    cout<<"*p is "<<*p<<endl;
    cout<<"**p2 is "<<**p2<<endl;

    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"&i is "<<&i<<endl;
    cout<<"p is "<<p<<endl;
    cout<<"*p2 is "<<*p2<<endl;

    cout<<endl;
    cout<<endl;
    cout<< &p<<endl;
    cout<< p <<endl;

    cout<<endl;
    cout<<endl;
    cout<<"before"<<endl;
    cout<<"I is "<<i<<endl;
    cout<<"p is "<<p<<endl;
    cout<<"p2 is "<<p2<<endl;
    update(p2);
    cout<<"After"<<endl;
    cout<<"I is "<<i<<endl;
    cout<<"p is "<<p<<endl;
    cout<<"p2 is "<<p2<<endl;



    
    return 0;
}