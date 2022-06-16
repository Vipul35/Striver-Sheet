class Solution {
public:
    void dfs(vector<vector<int>> &image,int i,int j,int color,vector<vector<bool>> &visited,int img)
    {
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() ||
          visited[i][j]==true || image[i][j]!=img)
        {
            return;
        }
        visited[i][j]=true;
        image[i][j]=color;
        dfs(image,i+1,j,color,visited,img);
        dfs(image,i-1,j,color,visited,img);
        dfs(image,i,j+1,color,visited,img);
        dfs(image,i,j-1,color,visited,img);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<bool>> visited(image.size(),vector<bool> (image[0].size(),0));
        if(image[sr][sc]!=color)
        {
       dfs(image,sr,sc,color,visited,image[sr][sc]);
        }
        return image;
    }
};