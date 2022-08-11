class Solution {
public:
    int getchar(char a)
    {
        if(a=='I')
        {
            return 1;
        }
        if(a=='V')
        {
            return 5;
        }
        if(a=='X')
        {
            return 10;
        }
        if(a=='L')
        {
            return 50;
        }
        if(a=='C')
        {
            return 100;
        }
        if(a=='D')
        {
            return 500;
        }
        if(a=='M')
        {
            return 1000;
        }
        return 0;
    }
    int romanToInt(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            int x1=getchar(s[i]);
            int x2=getchar(s[i+1]);
            if(x1>=x2)
            {
                ans+=x1;
            }
            else
            {
                int subtract=abs(x2-x1);
                ans+=subtract;
                i++;
            }
        }
        return ans;
    }
};