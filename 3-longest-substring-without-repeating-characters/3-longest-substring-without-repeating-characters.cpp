class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> visited;
        int i=0;
        int j=0;
        int n=s.size();
        int ans=0;
        while(j<n)
        {
            while(visited.find(s[j])!=visited.end())
            {
                visited.erase(s[i]);
                i++;
            }
            visited.insert(s[j]);
            j++;
            ans=max(ans,j-i);
        }
        return ans;
    }
};