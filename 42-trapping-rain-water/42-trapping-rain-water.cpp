class Solution {
public:
    int trap(vector<int>& height) {
        int max_left=0;
        int max_right=0;
        int left=0;
        int right=height.size()-1;
        int ans=0;
        while(left<=right)
        {
            if(height[left]<=height[right])
            {
                if(max_left<height[left])
                {
                    max_left=height[left];
                }
                else
                {
                    ans+=max_left-height[left];
                }
                left++;
            }
            else
            {
                if(max_right<height[right])
                {
                    max_right=height[right];
                }
                else
                {
                    ans+=max_right-height[right];
                }
                right--;
            }
        }
        return ans;
    }
};