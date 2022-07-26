class Solution {
public:
    int majorityElement(vector<int> nums) {
        unordered_map<int,int> m;
        int x=0;
        for(auto it:nums)
        {
            m[it]++;
        }
        int ans=0;
        int cnt=-1;
        for(auto it:m)
        {
            if(it.second>cnt)
            {
                cnt=it.second;
                ans=it.first;
            }
        }
        return ans;
    }
};