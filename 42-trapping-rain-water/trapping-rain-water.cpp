class Solution {
public:
    vector<int> prefix(vector<int> & arr,int n)
    {
        vector<int> pre(n);
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                pre[i]=arr[i];
            }
            else
            {
                pre[i]=max(arr[i],pre[i-1]);
            }
        }
        return pre;
    }
    vector<int> sufix(vector<int> & arr,int n)
    {
        vector<int> suf(n);
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
            {
                suf[i]=arr[i];
            }
            else
            {
                suf[i]=max(arr[i],suf[i+1]);
            }
        }
        return suf;
    }
    int trap(vector<int>& arr) 
    {
        int n= arr.size();
        vector<int> pre=prefix(arr,n);
        vector<int> suf=sufix(arr,n);
        int total=0;
        for(int i=0;i<n;i++)
        {
            total+=min(pre[i],suf[i])-arr[i];
        }
        return total;
    }
};