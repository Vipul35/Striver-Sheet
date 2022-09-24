class Solution {
public:
    static bool compare(string a,string b)
    {
        string ab=a+b;
        string ba=b+a;
        return ab>ba;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> ans;
        for(int i=0;i<nums.size();i++)
        {
            ans.push_back(to_string(nums[i]));
        }
        sort(ans.begin(),ans.end(),compare);
        string s="";
        for(int i=0;i<ans.size();i++)
        {
            s+=ans[i];
        }
        if(s[0]=='0')
        {
            return "0";
        }
        return s;
    }
};