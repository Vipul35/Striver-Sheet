class Solution {
public:
    int longestpalindrome(string text1,string text2)
    {
        int n=text1.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
        }
        for(int j=0;j<=n;j++)
        {
            dp[0][j]=0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
    int minInsertions(string s) {
        string s2=s;
        reverse(s2.begin(),s2.end());
        return s.size()-longestpalindrome(s,s2);
    }
};