class MinStack {
public:
    stack<int> s1;
    stack<int> s2;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s1.empty() && s2.empty())
        {
            s1.push(val);
            s2.push(val);
        }
        else
        {
            if(s2.empty())
            {
                s2.push(val);
            }
            else if(val<=s2.top())
            {
                s2.push(val);
            }
            s1.push(val);
        }
    }
    
    void pop() {
        if(s1.top()==s2.top())
        {
            s1.pop();
            s2.pop();
        }
        else
        {
            s1.pop();
        }
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
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