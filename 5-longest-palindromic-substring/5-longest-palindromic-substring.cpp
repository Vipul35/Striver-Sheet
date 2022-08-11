class Solution {
public:
    string longestPalindrome(string s) {
        string res=s.substr(0,1);
        int maxi=1;
        if(s.size()<=1)
        {
            return s;
        }
        for(int i=0;i<s.size()-1;i++)
        {
            int l=i;
            int r=i;
            while(l>=0 && r<s.size() && s[l]==s[r])
            {
                if(r-l+1>maxi)
                {
                    maxi=r-l+1;
                    res=s.substr(l,r-l+1);
                }
                l--;
                r++;
            }
            l=i;
            r=i+1;
            while(l>=0 && r<s.size() && s[l]==s[r])
            {
                if(r-l+1>maxi)
                {
                    maxi=r-l+1;
                    res=s.substr(l,r-l+1);
                }
                l--;
                r++;
            }
        }
        return res;
    }
};