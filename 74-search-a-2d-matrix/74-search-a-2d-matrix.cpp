class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size()-1;
        int i=0;
        while(i<n && m>=0)
        {
            if(target==matrix[i][m])
            {
                return true;
            }
            else if(matrix[i][m]>target)
            {
                m--;
            }
            else
            {
                i++;
            }
        }
        return false;
    }
};