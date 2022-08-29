class MinStack {
public:
    stack<pair<int,int>> s;
    int size=0;
    MinStack() {
        
    }
    void push(int val) {
        int mini;
        if(size==0)
        {
            size++;
            mini=val;
        }
        else
        {
            size++;
            int value=s.top().second;
            mini=min(val,value);
        }
        s.push({val,mini});
    }
    
    void pop() {
        s.pop();
        size--;
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
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