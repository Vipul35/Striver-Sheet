class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int ans=-1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]>nums[i])
            {
                ans=i-1;
                break;
            }
            // else if(nums[i-1]<nums[i])
            // {
            //     ans=i;
            // }
        }
        if(ans==-1)
        {
            return nums.size()-1;
        }
        return ans;
    }
    
};