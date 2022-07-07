class Solution {
public:
    bool palindrome(string s,int i,int j)
    {
        while(i<=j)
        {
            if(s[i++]!=s[j--])
            {
                return false;
            }
        }
        return true;
    }
    void fun(string s,vector<vector<string>> &v,int idx,vector<string> &temp)
    {
        if(idx==s.size())
        {
            v.push_back(temp);
            return;
        }
        for(int i=idx;i<s.size();i++)
        {
            if(palindrome(s,idx,i))
            {
                temp.push_back(s.substr(idx,i-idx+1));
                fun(s,v,i+1,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        fun(s,ans,0,temp);
        return ans;
    }
};