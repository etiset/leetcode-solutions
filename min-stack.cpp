class MinStack {
private:
    stack<int> st, min_st;

public:
    MinStack() {
    }
    
    void push(int val) {
        if(min_st.empty() || getMin() >= val){
            min_st.push(val);
        }

        st.push(val);
    }
    
    void pop() {
        if(st.top() == getMin()){
            min_st.pop();
        }

        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
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