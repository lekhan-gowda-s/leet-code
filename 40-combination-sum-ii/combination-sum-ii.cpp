class Solution {
public:
    void fs(int idx, vector<int>& arr, vector<int>& ds, int target,vector<vector<int>>& ans)  
    {
        if(target==0)
        {
            ans.push_back(ds);
            return;
        }

        for(int i=idx;i<arr.size();i++)
        {
            if(i>idx && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;

            ds.push_back(arr[i]);
            fs(i+1,arr,ds,target-arr[i],ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target)
    {
        sort(arr.begin(), arr.end());

        vector<vector<int>> ans;
        vector<int> ds;

        fs(0, arr, ds, target,ans);

        return ans;
    }
};