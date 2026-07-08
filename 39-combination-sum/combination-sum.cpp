class Solution {
public:
    void fs(int i,int target,vector<int> &c,vector<vector<int>> &ans,vector<int> &ds)
    {
        if(i==c.size())
        {
            if(target==0)
            {
                ans.push_back(ds);
            }
            return;
        }
        if(c[i]<=target)
        {
            ds.push_back(c[i]);
            fs(i,target-c[i],c,ans,ds);
            ds.pop_back();
        }
        fs(i+1,target,c,ans,ds);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& c, int target) 
    {
        vector<vector<int>> ans;
        vector<int> ds;
        int i=0;
        fs(i,target,c,ans,ds);
        return ans;
        
    }
};