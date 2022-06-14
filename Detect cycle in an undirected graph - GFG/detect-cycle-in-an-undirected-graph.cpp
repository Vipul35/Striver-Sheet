// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool cycle_helper(vector<int> adj[],unordered_map<int,bool> &visited,int parent,int node)
    {
        visited[node]=1;
        for(auto nbr:adj[node])
        {
            if(visited[nbr]==0)
            {
                if(cycle_helper(adj,visited,node,nbr))
                {
                    return true;
                }
            }
            else if(nbr!=parent)
            {
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int,bool> visited;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(cycle_helper(adj,visited,-1,i))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends