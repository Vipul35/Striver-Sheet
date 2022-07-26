class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int idx=intervals[0][0];
        int end=intervals[0][1];
        vector<vector<int>> v;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<=end)
            {
                end=max(intervals[i][1],end);
                
            }
            else
            {
                v.push_back({idx,end});
                idx=intervals[i][0];
                end=intervals[i][1];
            }
            
        }
        v.push_back({idx,end});
        return v;
    }
};