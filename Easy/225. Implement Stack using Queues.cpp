class MyStack {
public:
    queue<int> Q;
    /** Initialize your data structure here. */
    MyStack()
    {
        
    }
    
    /** Push element x onto stack. */
    void push(int x)
    {
        vector<int> V(Q.size());
        int i = -1;
        while(!Q.empty())
        {
            int front = Q.front();
            Q.pop();
            V[++i] = front;
        }

        Q.push(x);
        
        for(int i = 0; i < V.size(); i++)
            Q.push(V[i]);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int front = Q.front();
        Q.pop();
        return front;
    }
    
    /** Get the top element. */
    int top()
    {
        return Q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty()
    {
        return Q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */