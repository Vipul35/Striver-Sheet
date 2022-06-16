class Solution {
public:
    void dfs(vector<vector<int>> &image,int i,int j,int color,int img)
    {
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() ||
         image[i][j]!=img)
        {
            return;
        }
        image[i][j]=color;
        dfs(image,i+1,j,color,img);
        dfs(image,i-1,j,color,img);
        dfs(image,i,j+1,color,img);
        dfs(image,i,j-1,color,img);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]!=color)
        {
       dfs(image,sr,sc,color,image[sr][sc]);
        }
        return image;
    }
};