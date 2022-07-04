class Solution {
public:
    void sum(int idx,vector<int> &v,vector<int> candidates,int target,vector<vector<int>> &ans)
    {
        if(idx==candidates.size())
        {
         return;
        }
        if(target==0)
        {
            ans.push_back(v);
            return;
        }
        if(candidates[idx]<=target)
        {
            v.push_back(candidates[idx]);
            sum(idx,v,candidates,target-candidates[idx],ans);
            v.pop_back();
        }
        sum(idx+1,v,candidates,target,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        vector<vector<int>> ans;
        sum(0,v,candidates,target,ans);
        return ans;
    }
};