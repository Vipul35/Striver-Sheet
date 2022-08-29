class MinStack {
public:
    int a[10000];
    int b[10000];
    int i=0;
    int size=0;
    MinStack() {
        
    }
    
    void push(int val) {
        a[i]=val;
        i++;
        size++;
    }
    
    void pop() {
             size--;
             i--;
    }
    
    int top() {
        return a[size-1];
    }
    
    int getMin() {
        for(int i=0;i<size;i++)
        {
            b[i]=a[i];
        }
        sort(b,b+size);
        return b[0];
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