class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        
     // Push x to queue2
        q2.push(x);
        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        // Swap names of q1 and q2
        std::swap(q1, q2);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }
    
    /** Get the top element. */
    int top() {
        return q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }

private:
    std::queue<int> q1, q2; // Queue1 and Queue2
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */