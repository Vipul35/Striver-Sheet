class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt1=0;
        int cnt2=0;
        int cnt3=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                ++cnt1;
            }
            if(nums[i]==1)
            {
                ++cnt2;
            }
            if(nums[i]==2)
            {
                ++cnt3;
            }
        }
        nums.erase(nums.begin(),nums.end());
        for(int i=0;i<cnt1;i++)
        {
            nums[i]=0;
            nums.push_back(nums[i]);
        }
        for(int j=0;j<cnt2;j++)
        {
            nums.push_back(1);
        }
        for(int k=0;k<cnt3;k++)
        {
            nums.push_back(2);
        }
    }
};