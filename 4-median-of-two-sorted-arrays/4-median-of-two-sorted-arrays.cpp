class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int len=n+m;
        int temp[len+1];
        for(int i=0;i<n;i++)
        {
            temp[i]=nums1[i];
        }
        for(int i=0;i<m;i++)
        {
            temp[n+i]=nums2[i];
        }
        sort(temp,temp+len);
        double ans=0;
        if((n+m)%2==0)
        {
            ans=(temp[len/2]+temp[(len/2)-1]);
            ans=ans/2;
        }
        else
        {
            ans=temp[len/2];
        }
        return ans;
    }
};