class Solution {
public:
    int f(int n,int idx,int prev,vector<vector<int>> &dp,vector<int> &nums)
    {
        if(idx==n)
        {
            return 0;
        }
        if(dp[idx][prev+1]!=-1)
        {
            return dp[idx][prev+1];
        }
        int len=f(n,idx+1,prev,dp,nums);
        if(prev==-1 || nums[idx]>nums[prev])
        {
            len=max(len,1+f(n,idx+1,idx,dp,nums));
        }
        return dp[idx][prev+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        return f(n,0,-1,dp,nums);
    }
};