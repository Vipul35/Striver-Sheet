class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            string res;
            if(s[i]==' ')
            {
                continue;
            }
            while(s[i]!=' ' &&  i<n)
            {
                res+=s[i++];
            }
            st.push(res);
        }
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
            if(!st.empty())
            {
                ans+=' ';
            }
        }
        return ans;
    }
};