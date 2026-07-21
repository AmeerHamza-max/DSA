#include<iostream>
using namespace std;
int main(){
    int a = 3;
    cout<<a<<endl;
    if(true){
        int a = 5;
        cout << a <<endl;
        int b = 10;
    }
    int b = 1;
    cout<< b << endl;// this will through an error you had to initialize it outside the blocks 
    int i = 8;

    for(int i = 0; i<8; i++){
        cout<<"HI"<<endl;
    }
    if(1){
        int b; 
        if(1){
            int b;
            if(1){
                int b;
            }
        }
    }
}