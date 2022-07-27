class Solution {
public:
    int coin(vector<int> &coins,int amount,vector<vector<int>> &dp,int idx)
    {
        if(idx==0)
        {
            if(amount%coins[0]==0)
            {
                return amount/coins[0];
            }
            else
            {
                return 1e+9;
            }
        }
        if(dp[idx][amount]!=-1)
        {
            return dp[idx][amount];
        }
        int not_take=coin(coins,amount,dp,idx-1);
        int take=INT_MAX;
        if(amount>=coins[idx])
        {
            take=1+coin(coins,amount-coins[idx],dp,idx);
        }
        return dp[idx][amount]=min(not_take,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        int ans=coin(coins,amount,dp,n-1);
        if(ans>=1e+9)
        {
            return -1;
        }
        return ans;
    }
};