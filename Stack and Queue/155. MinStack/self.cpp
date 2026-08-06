#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class MinStack {
private:
    vector <int> st;
    vector <int> minst;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        st.push_back(value);
        if(minst.empty()){
            minst.push_back(value);
        }
        else{
            minst.push_back(min(value,minst.back()));
        }
    }
    
    void pop() {
        minst.pop_back();
        st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return minst.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */