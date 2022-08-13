class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> v;
        int num=n;
        while(n>0)
        {
            int digit=n%10;
            v.push_back(digit);
            n=n/10;
        }
        reverse(v.begin(),v.end());
        next_permutation(v.begin(),v.end());
        long ans=0;
        for(int i=0;i<v.size();i++)
        {
            ans=ans*10;
            ans+=v[i];
        }
        if(ans>INT_MAX || ans<=num)
        {
            return -1;
        }
        return ans;
    }
};