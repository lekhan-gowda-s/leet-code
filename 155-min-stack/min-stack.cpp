class MinStack {
public:
    stack<long long> st;
    long long mini; 
    MinStack() 
    {
         mini=INT_MAX;  
    }
    
    void push(int value) 
    {
        
        if(st.empty())
        {
            st.push(value);
            mini=value;
        }
        else if(value<mini)
        {
            st.push(2LL*value-mini);
            mini=value;
        }
        else
        {
            st.push(value);
        }
    }
    
    void pop() 
    {
        if(st.empty())
        {
            mini = INT_MAX;
            return;
        }
        else if(st.top()<mini)
        {
            mini=2LL *mini-st.top();
            st.pop();
        } 
        else
        {
            st.pop();
        } 
    }
    
    int top() 
    {
        if(st.empty())
        {
            return 0;
        }
        if(st.top()<mini)
        {
            return mini;
        }
        else
        {
            return st.top();
        }
    }
    
    int getMin() 
    {
        return mini;
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