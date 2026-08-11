#include <bits/stdc++.h>

using namespace std;


/*
st1 mimicks the real stack
st2's top always stores the minimum value
*/
class MinStack {
public:
    stack<int> st1, st2;
    MinStack() {

    }
    
    void push(int value) {
        st1.push(value);

        if(st2.empty() || st2.top() >= value)
            st2.push(value);
    }
    
    void pop() {
        if(!st2.empty() && st2.top() == st1.top())
            st2.pop();

        st1.pop();
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top();
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