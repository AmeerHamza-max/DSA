#include<iostream>
using namespace std;
void update(int& n){
    n++;
}
int& func(int a){// bad practice 
    int num = a;
    int& ans = num;
    return ans;
}
int main(){
    int i = 5;
    //create a ref variable
    int &j = i;
    cout<<"Before I = "<<i<<endl;
    i++;
    cout<<"After I++ = "<<i<<endl;
    j++;
    cout<<"After J++ = "<<i<<endl;
    int n = 5;
    cout<<"Before "<<n<<endl;
    update(n);
    cout<<"after "<<n<<endl;

    cout<<func(n)<<endl;
    return 0;

    

}