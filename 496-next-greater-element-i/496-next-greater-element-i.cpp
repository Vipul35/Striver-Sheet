class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        for(int i=0;i<nums2.size();i++)
        {
            m[nums2[i]]=i;
        }
        vector<int> v;
        for(int i=0;i<nums1.size();i++)
        {
            int x=m[nums1[i]];
                int ans=-1;
            for(int j=x+1;j<nums2.size();j++)
            {
                if(nums2[j]>nums1[i])
                {
                    ans=nums2[j];
                    break;
                }
            }
                v.push_back(ans);
        }
        return v;
    }
};