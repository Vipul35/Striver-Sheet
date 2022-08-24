class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1=version1.size();
        int n2=version2.size();
        int i=0;
        int j=0;
        while(i<n1 || j<n2)
        {
            int res1=0;
            int res2=0;
            while(i<n1 && version1[i]!='.')
            {
                int digit=(version1[i]-'0');
                res1=res1*10+digit;
                i++;
            }
            while(j<n2 && version2[j]!='.')
            {
                int digit2=(version2[j]-'0');
                res2=res2*10+digit2;
                j++;
            }
            if(res1>res2)
            {
                return 1;
            }
            else if(res2>res1)
            {
                return -1;
            }
            i++;
            j++;
        }
        return 0;
    }
};