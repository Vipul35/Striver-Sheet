// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int dfs(vector<vector<int>> &grid,vector<vector<bool>> &visited,int i,int j)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0 || visited[i][j])
        {
            return 0;
        }
        visited[i][j]=true;
        return 1+dfs(grid,visited,i+1,j)+dfs(grid,visited,i-1,j)+dfs(grid,visited,i-1,j-1)+dfs(grid,visited,i-1,j+1)+dfs(grid,visited,i+1,j+1)+
        dfs(grid,visited,i,j+1)+dfs(grid,visited,i,j-1)+dfs(grid,visited,i+1,j-1);
    }
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        vector<vector<bool>> visited(grid.size(),vector<bool> (grid[0].size(),false));
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(!visited[i][j] && grid[i][j]==1)
                {
                    ans=max(ans,dfs(grid,visited,i,j));
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends