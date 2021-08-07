class MyQueue {
    stack<int> S;

public:
    /** Initialize your data structure here. */
    MyQueue()
    {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x)
    {
        vector<int> V(S.size());
        int i = -1;
        while(!S.empty())
        {
            int top = S.top();
            S.pop();
            V[++i] = top;
        }
        
        S.push(x);

        for(i = V.size() - 1; i >= 0; --i)
            S.push(V[i]);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        int top = S.top();
        S.pop();
        return top;
    }
    
    /** Get the front element. */
    int peek()
    {
        return S.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty()
    {
        return S.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */