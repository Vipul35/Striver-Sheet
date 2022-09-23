class Solution {
public:
   
    void letter(string &v,vector<string> &ans,string &digits,int i,unordered_map<int,string> &m)
    {
        if(v.size()==digits.size())
        {
            ans.push_back(v);
            return;
        }
        for(auto it:m[digits[i]-'0'])
        {
            v+=it;
            letter(v,ans,digits,i+1,m);
            v.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
        {
            return {};
        }
        string v;
         unordered_map<int,string> m;
         m[2]="abc";
         m[3]="def";
         m[4]="ghi";
         m[5]="jkl";
         m[6]="mno";
         m[7]="pqrs";
         m[8]="tuv";
         m[9]="wxyz";
        vector<string> ans;
         letter(v,ans,digits,0,m);
         return ans;
    }
};