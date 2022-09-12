class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int cnt=0;
        int idx=0;
        vector<int> v;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==target && cnt==0)
            {
                idx=i;
                v.push_back(i);
                cnt++;
            }
            else if(nums[i]==target && cnt>0)
            {
                cnt++;
                
            }
        }
        if(cnt==0)
        {
            v.push_back(-1);
            v.push_back(-1);
        }
        else
        {
            v.push_back(idx+cnt-1);
        }
        return v;
    }
};