class Solution {
public:
    void subset(vector<int> &v,vector<vector<int>> &ans,vector<int> nums,int i)
    {
        ans.push_back(v);
        if(i==nums.size())
        {
            return;
        }
        for(int j=i;j<nums.size();j++)
        {
            if(j!=i && nums[j]==nums[j-1])
            {
                continue;
            }
            v.push_back(nums[j]);
            subset(v,ans,nums,j+1);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> v;
        subset(v,ans,nums,0);
        return ans;
    }
};