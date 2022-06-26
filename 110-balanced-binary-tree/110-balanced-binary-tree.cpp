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
    int height(TreeNode*root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int ls=height(root->left);
        int rs=height(root->right);
        return 1+max(ls,rs);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }
        int left=height(root->left);
        int right=height(root->right);
        if(abs(left-right)>1)
        {
            return false;
        }
        return isBalanced(root->right)&&isBalanced(root->left);
    }
};