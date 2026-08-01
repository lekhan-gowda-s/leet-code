class Solution {
public:
    void fs(int idx,vector<int> &c,vector<int> & arr,vector<vector<int>> &ans)
{
    if(idx==arr.size())
    {
        ans.push_back(c);   
        return;
    }
    c.push_back(arr[idx]);
    fs(idx+1,c,arr,ans);
    c.pop_back();
    fs(idx+1,c,arr,ans);
}
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<int> c;
        vector<vector<int>> ans;
        fs(0,c,nums,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};