class Solution {
public:
    bool cycle(int node,unordered_map<int,bool> &visited,unordered_map<int,bool> &dfsvisited,vector<int> adj[])
    {
        visited[node]=true;
        dfsvisited[node]=true;
        for(auto nbr:adj[node])
        {
            if(!visited[nbr])
            {
                if(cycle(nbr,visited,dfsvisited,adj))
                {
                    return true;
                }
            }
            else if(dfsvisited[nbr])
            {
                return true;
            }
        }
        dfsvisited[node]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto x:prerequisites)
        {
            adj[x[1]].push_back(x[0]);
        }
        unordered_map<int,bool> visited;
        unordered_map<int,bool> dfsvisited;
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
            {
                if(cycle(i,visited,dfsvisited,adj))
                {
                    return false;
                }
            }
        }
        return true;
    }
};