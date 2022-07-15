class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=1;
        int maxleft=INT_MIN;
        int maxright=INT_MIN;
        int zero=0;
        for(int i=0;i<nums.size();i++)
        {
            ans=ans*nums[i];
            if(nums[i]==0)
            {
                zero=1;
                ans=1;
                continue;
            }
            maxleft=max(maxleft,ans);
        }
        ans=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            ans=ans*nums[i];
            if(nums[i]==0)
            {
                zero=1;
                ans=1;
                continue;
            }
            maxright=max(maxright,ans);
        }
        if(zero==1)
        {
            return max(0,max(maxright,maxleft));
        }
        return max(maxleft,maxright);
    }
};