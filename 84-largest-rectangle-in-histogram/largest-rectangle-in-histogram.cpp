class Solution {
public:
    int largestRectangleArea(vector<int>& arr) 
    {
        stack<int> st;
        int ma=INT_MIN;
        for(int i=0;i<arr.size();i++)
        {
            while(!st.empty() && arr[st.top()] > arr[i])
    {
    int el = st.top();
    st.pop();

    if(st.empty())
    {
        ma = max(ma, arr[el] * i);
    }
    else
    {
        ma = max(ma, arr[el] * (i - st.top() - 1));
    }
}
            if(st.empty())
            {
                st.push(i);
            }
            else
            {
                st.push(i);
            }
        }
        while(!st.empty())
        {
            int elem=arr[st.top()];
            st.pop();
            if(st.empty())
            {
                ma = max(ma, elem * (int)arr.size());
            }
            else
            {
                ma=max(ma,elem*(int)(arr.size()-st.top()-1));
            }
        }
        return ma;
    }
};