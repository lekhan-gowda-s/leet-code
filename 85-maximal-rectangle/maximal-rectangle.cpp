class Solution {
public:
    int histo(vector<int>& x)
    {
        stack<int> st;
        int mas=INT_MIN;
        for(int i=0;i<x.size();i++)
        {
            while(!st.empty() && x[st.top()]>x[i])
            {
                int ele=st.top();
                st.pop();
                if (st.empty())
                {
                    mas = max(mas, x[ele] * i);
                }
                else
                {
                    mas = max(mas, x[ele] * (i - st.top() - 1));
                }
            }
            st.push(i);
        }
         while(!st.empty())
            {
                int ele=st.top();
                st.pop();
                if(!st.empty())
                {
                    mas=max(mas,x[ele]*(int)(x.size()-st.top()-1));
                }
                else
                {
                    mas=max(mas,x[ele]*(int)(x.size()));
                }
            }
        return mas;
    }
    int maximalRectangle(vector<vector<char>>& arr) 
    {    
        int ma=INT_MIN;
        int row=arr.size();
        int col=arr[0].size();
        vector<vector<int>> pre(row, vector<int>(col));
        for(int i=0;i<arr.size();i++)
        {
            int sum = 0;
            for(int j=0;j<arr[0].size();j++)
            {
                if(arr[i][j] == '1')
                    {
                        if(i == 0)
                        pre[i][j] = 1;
                else
                        pre[i][j] = pre[i-1][j] + 1;
                    }
else
{
    pre[i][j] = 0;
}
            }
        }

        for(int i=0;i<row;i++)
        {
            ma=max(ma,histo(pre[i]));
        }
        return ma;
    }
};