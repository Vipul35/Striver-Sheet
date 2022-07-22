class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> temp;
        for(int i=matrix.size()-1;i>=0;i--)
        {
            vector<int> v;
            for(int j=0;j<matrix[0].size();j++)
            {
                v.push_back(matrix[i][j]);
            }
            temp.push_back(v);
            v.clear();
        }
        for(int j=0;j<matrix[0].size();j++)
        {
            for(int i=0;i<matrix.size();i++)
            {
                matrix[j][i]=temp[i][j];
            }
        }
    }
};