class MinStack {
private:
    stack<int> st;
    stack<int> min_st;

public:
    MinStack() {
    }
    
    void push(int value) {
        st.push(value);

        if(min_st.empty() || min_st.top() >= value){
            min_st.push(value);
        }
    }
    
    void pop() {
        if(min_st.top() == st.top()){
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
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */