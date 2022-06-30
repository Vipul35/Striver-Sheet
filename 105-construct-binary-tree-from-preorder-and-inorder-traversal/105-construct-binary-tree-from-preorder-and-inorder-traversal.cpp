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
    int idx=0;
    TreeNode*build(vector<int> preorder,vector<int> inorder,unordered_map<int,int> &m,int s,int e)
    {
        if(s>e)
        {
            return NULL;
        }
        TreeNode*root=new TreeNode(preorder[idx]);
        int pos=m[preorder[idx]];
        idx++;
        root->left=build(preorder,inorder,m,s,pos-1);
        root->right=build(preorder,inorder,m,pos+1,e);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++)
        {
            m[inorder[i]]=i;
        }
        return build(preorder,inorder,m,0,inorder.size()-1);
    }
};