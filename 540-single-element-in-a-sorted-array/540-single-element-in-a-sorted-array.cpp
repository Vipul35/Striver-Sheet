class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        set<int> s;
        for(int i=0;i<nums.size();i++)
        {
            if(s.find(nums[i])!=s.end())
            {
                s.erase(nums[i]);
            }
            else if(s.find(nums[i])==s.end())
            {
                s.insert(nums[i]);
            }
        }
        int ans=0;
        for(auto it:s)
        {
            ans=it;
        }
        return ans;
    }
};