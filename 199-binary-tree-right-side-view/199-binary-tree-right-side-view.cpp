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
    void right(TreeNode*root,vector<int> &v,int level,int &maxlevel)
    {
        if(root==NULL)
        {
            return;
        }
        if(level>maxlevel)
        {
            maxlevel=level;
            v.push_back(root->val);
        }
        right(root->right,v,level+1,maxlevel);
        right(root->left,v,level+1,maxlevel);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        int maxlevel=-1;
        right(root,v,0,maxlevel);
        return v;
    }
};