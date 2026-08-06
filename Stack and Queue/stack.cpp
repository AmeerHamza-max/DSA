#include<iostream>
using namespace std;
int top = -1;
int arr[10];
bool isEmpty(){
    return top<0;
}
void push(int n){
    if(top >= 9){
        cout<<"Stack overflow"<<endl;
        return ;
    }
    arr[++top]=n;
    cout<<"Element "<<n<<" pushed in stack"<<endl;
}
void pop(){
    if(isEmpty()){
        cout<<"Stack underflow "<<endl;
        return ;
    }
    cout<<arr[top]<<" popped"<<endl;
    top--;
    
}
void peak(){
    if(isEmpty()){
        cout << "Stack is empty" << endl;
        return;
    }
    cout<<arr[top]<<" top element"<<endl;
}
int main(){
    push(10);
    push(20);
    push(30);
    peak();
    pop();
    peak();
    for(int i = 0 ; i <= top;i++){
        cout<<arr[i]<<" ";
    }

}