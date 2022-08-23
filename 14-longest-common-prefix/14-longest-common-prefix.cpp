class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int mini=INT_MAX;
        for(int i=0;i<strs.size();i++)
        {
            int n=strs[i].size();
            mini=min(mini,n);
        }
        for(int i=0;i<mini;i++)
        {
            char ch=strs[0][i];
            for(int j=0;j<strs.size();j++)
            {
                if(ch!=strs[j][i])
                {
                    return ans;
                }
            }
            ans+=ch;
        }
        return ans;
    }
};