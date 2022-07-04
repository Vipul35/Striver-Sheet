class Solution {
public:
    void sum(int idx,vector<vector<int>> &ans,vector<int> v,vector<int> candidates,int target)
    {
        if(target==0)
        {
            ans.push_back(v);
            return;
        }
        for(int i=idx;i<candidates.size();i++)
        {
            if(i>idx && candidates[i]==candidates[i-1])
            {
                continue;
            }
            if(target<candidates[i])
            {
                break;
            }
            v.push_back(candidates[i]);
            sum(i+1,ans,v,candidates,target-candidates[i]);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        sum(0,ans,v,candidates,target);
        return ans;
    }
};