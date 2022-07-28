class Solution {
public:
   static bool compare(string a,string b)
    {
        string ab=a+b;
        string ba=b+a;
        return ab>ba;
    }
    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        vector<string> res;
        for(int i=0;i<nums.size();i++)
        {
            res.push_back(to_string(nums[i]));
        }
        sort(res.begin(),res.end(),compare);
        string result="";
        for(auto &it:res)
        {
            result+=it;
        }
        if(result[0]=='0')
        {
            return "0";
        }
        return result;
    }
};