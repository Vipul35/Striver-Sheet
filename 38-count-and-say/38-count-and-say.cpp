class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
        {
            return "1";
        }
        string s=countAndSay(n-1);
        int counter=1;
        string res="";
        for(int i=0;i<s.length();i++)
        {
            while(s[i]==s[i+1])
            {
                counter++;
                i++;
            }
            res=res+to_string(counter)+s[i];
            counter=1;
        }
        return res;
    }
};