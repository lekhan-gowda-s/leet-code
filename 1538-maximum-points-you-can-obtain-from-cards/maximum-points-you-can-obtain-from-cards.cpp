class Solution {
public:
    int maxScore(vector<int>& arr, int k) 
    {
        int l=0,r=arr.size();
        int ans=0,sum=0;
        for(int i=0;i<k;i++)
        {
            sum+=arr[i];
            l=i;
        }    
        ans=sum;
        while(l>=0)
        {
            sum-=arr[l];
            l--;
            r--;
            sum+=arr[r];
            ans=max(ans,sum);
        }
        return ans;
    }
};