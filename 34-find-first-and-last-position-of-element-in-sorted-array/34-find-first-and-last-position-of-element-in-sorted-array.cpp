class Solution {
public:
    int occurence(vector<int> nums,int target,bool first)
    {
        int s=0;
        int e=nums.size()-1;
        int ans=-1;
        while(s<=e)
        {
            int mid=(s+e)/2.0;
            if(nums[mid]==target)
            {
                ans=mid;
                if(first)
                {
                    e=mid-1;
                }
                else
                {
                    s=mid+1;
                }
            }
            else if(nums[mid]<target)
            {
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        bool first=true;
        vector<int> v;
        int a=occurence(nums,target,first);
        int b=occurence(nums,target,false);
        v.push_back(a);
        v.push_back(b);
        return v;
    }
};