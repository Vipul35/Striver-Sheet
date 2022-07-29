class Solution {
public:
    bool fun(vector<int> &nums,int idx,vector<vector<int>> &dp,int sum)
    {
        if(sum==0)
        {
            return true;
        }
        if(idx==0)
        {
            return nums[0]==sum;
        }
        if(dp[idx][sum]!=-1)
        {
            return dp[idx][sum];
        }
        bool not_take=fun(nums,idx-1,dp,sum);
        bool take=false;
        if(sum>=nums[idx])
        {
            take=fun(nums,idx-1,dp,sum-nums[idx]);
        }
        return dp[idx][sum]=take||not_take;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        vector<vector<int>> dp(nums.size(),vector<int> (sum+1,-1));
        if(sum%2==0)
        {
           return fun(nums,nums.size()-1,dp,sum/2);
        }
        return false;
    }
};