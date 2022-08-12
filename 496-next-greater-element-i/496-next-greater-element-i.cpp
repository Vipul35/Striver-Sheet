class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nge(nums1.size());
        stack<int> s;
        s.push(-1);
        unordered_map<int,int> m;
        for(int i=nums2.size()-1;i>=0;i--)
        {
            while(s.top()!=-1 && nums2[i]>=s.top())
            {
                s.pop();
            }
            m[nums2[i]]=s.top();
            s.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++)
        {
            nge[i]=m[nums1[i]];
        }
        return nge;
    }
};