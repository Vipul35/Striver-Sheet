class Solution {
public:
   
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        vector<int> v;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto it:m)
        {
            pq.push({-(it.second),it.first});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        for(int i=0;i<k;i++)
        {
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
    }
};