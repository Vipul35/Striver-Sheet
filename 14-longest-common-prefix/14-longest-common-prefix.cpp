class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
        {
            return "";
        }
        string s="";
        sort(strs.begin(),strs.end());
        string a=strs[0];
        string b=strs[strs.size()-1];
        for(int i=0;i<a.size();i++)
        {
            if(a[i]==b[i])
            {
                s+=a[i];
            }
            else
            {
                break;
            }
        }
        return s;
    }
};