class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int maxi=INT_MAX;
        int mini=INT_MIN;
        while(i<s.length() && s[i]==' ')
        {
            i++;
        }
        if(i>=s.length())
        {
            return 0;
        }
        int pos=1;
        if(s[i]=='+')
        {
            i++;
        }
        else if(s[i]=='-')
        {
            pos=-1;
            i++;
        }
        long result=0;
        while(i<s.length() && s[i]>='0' && s[i]<='9')
        {
            int digit=(s[i]-'0');
            result=result*10+digit;
            if(result>=maxi || result<=mini)
            {
                break;
            }
            i++;
            
        }
        if(pos==-1)result=result*-1;
        if(result>=INT_MAX)return INT_MAX;
        else if(result<=INT_MIN)return INT_MIN;
        return result;
    }
};