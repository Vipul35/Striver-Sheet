/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode*root,vector<pair<int,pair<int,int>>> &v,int i,int j)
    {
        if(root==NULL)
        {
            return;
        }
        v.push_back({j,{i,root->val}});
        dfs(root->left,v,i+1,j-1);
        dfs(root->right,v,i+1,j+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<pair<int,pair<int,int>>> v;
        int rowlevel=0;
        int collevel=0;
        dfs(root,v,rowlevel,collevel);
        vector<vector<int>> vec;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
             vector<int> temp;
            int j=v[i].first;
            while(i<v.size() && j==v[i].first)
            {
                temp.push_back(v[i].second.second);
                i++;
            }
            vec.push_back(temp);
            i--;
        }
        return vec;
    }
};