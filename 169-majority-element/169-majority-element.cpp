class Solution {
public:
    int majorityElement(vector<int>& a) {
        sort(a.begin(),a.end());
        int ele=a[0];
        int cnt=1;
        int ans=0;
        for(int i=1;i<a.size()-1;i++)
        {
            if(a[i]==a[i+1])
            {
                cnt++;
                if(cnt>ans)
                {
                    ele=a[i];
                }
            }
            else
            {
                ans=max(ans,cnt);
                cnt=0;
            }
        }
        return ele;
    }
};