class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
        {
            return 0;
        }
        sort(nums.begin(),nums.end());
        int ans=1;
        int cnt=1;
        int prev=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==prev+1)
            {
                cnt++;
            }
            else if(nums[i]==prev)
            {
                continue;
            }
            else
            {
                cnt=1;
            }
            ans=max(ans,cnt);
            prev=nums[i];
        }
        return ans;
    }
};