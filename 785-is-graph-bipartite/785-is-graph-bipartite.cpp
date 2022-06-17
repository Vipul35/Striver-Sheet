class Solution {
public:
    bool dfs(vector<vector<int>> &graph,vector<int> &val,int node)
    {
        if(val[node]==-1)
        {
            val[node]=1;
        }
        for(auto nbr:graph[node])
        {
            if(val[nbr]==-1)
            {
            val[nbr]=1-val[node];
            if(dfs(graph,val,nbr))
            {
                return true;
            }
            }
            else if(val[nbr]==val[node])
            {
                return true;
            }
        }
        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> val(n,-1);
        for(int i=0;i<graph.size();i++)
        {
            if(val[i]==-1)
                {
                    if(dfs(graph,val,i))
                    {
                        return false;
                    }
                }
        }
        return true;
    }
};