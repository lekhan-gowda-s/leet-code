class Solution {
public:
    vector<int> l(vector<int>& arr,int n)
    {
       vector<int> nsl(n);
       stack<int> st;
       for(int i=0;i<n;i++)
       {
        while(!st.empty()&& arr[st.top()]>arr[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            nsl[i]=-1;
            st.push(i);
        }
        else
        {
            nsl[i]=st.top();
            st.push(i);
        }
       } 
       return nsl;
    }
    vector<int> r(vector<int>& arr,int n)
    {
       vector<int> nsr(n);
       stack<int> st;
       for(int i=n-1;i>=0;i--)
       {
        while(!st.empty()&& arr[st.top()]>=arr[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            nsr[i]=n;
            st.push(i);
        }
        else
        {
            nsr[i]=st.top();
            st.push(i);
        }
       } 
       return nsr;
    }
    int sumSubarrayMins(vector<int>& arr) 
    {
        int n= arr.size();
        vector<int> nl=l(arr,n);
        vector<int> nr=r(arr,n);
        long long ans=0;
        for(int i=0;i<arr.size();i++)
        {
            const long long MOD = 1000000007;
            long long ls = i - nl[i];
            long long rs = nr[i] - i;
            long long no=ls*rs*arr[i];
            ans = (ans + no) % MOD;
        }
        return ans;
          
    }
};