class MinStack {
    private:
    stack<int> st;    // Main stack to store all elements
    stack<int> minst; 
public:
    MinStack() {
        // stack<int> st;
        // stack<int> minst;
        
    }
    
    void push(int val) {
        st.push(val);
        
        if(minst.empty()){
            val = val;
        }
        else {
            val = min(val, minst.top());
        }
        
        minst.push(val);
        
    }
    
    void pop() {
        st.pop();
        minst.pop();
        
    }
    
    int top() {
        return st.top();
        
    }
    
    int getMin() {
        return minst.top();
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */