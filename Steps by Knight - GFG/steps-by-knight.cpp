// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    bool check(int n,int x,int y)
    {
        if(x>=1 && x<=n && y>=1 && y<=n)
        {
            return true;
        }
        return false;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int dx[]={-1,1,-1,1,-2,2,-2,2};
	    int dy[]={2,2,-2,-2,1,1,-1,-1};
	    bool visited[N+1][N+1];
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            visited[i][j]=false;
        }
    }
	    int xt=TargetPos[0];
	    int yt=TargetPos[1];
	    int xx=KnightPos[0];
	    int yy=KnightPos[1];
	    queue<pair<int,int>> q;
	    q.push({xx,yy});
	    int ans=0;
	    visited[xx][yy]=true;
	    while(!q.empty())
	    {
	        int s=q.size();
	        while(s--)
	        {
	            auto node=q.front();
	            q.pop();
	            int x=node.first;
	            int y=node.second;
	            if(x==xt && y==yt)
	            {
	                return ans;
	            }
	            for(int i=0;i<8;i++)
	            {
	                int xnew=x+dx[i];
	                int ynew=y+dy[i];
	                if(!(visited[xnew][ynew]) && check(N,xnew,ynew))
	                {
	                    visited[xnew][ynew]=true;
	                    q.push({xnew,ynew});
	                }
	            }
	        }
	        ans++;
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends