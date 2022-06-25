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
 
    void zigzag(TreeNode*root,vector<int> &v,int level,bool flag)
    {
        if(root==NULL)
        {
            return;
        }
        if(level==1)
        {
            v.push_back(root->val);
        }
        if(level>1)
        {
            if(flag)
            {
                zigzag(root->left,v,level-1,flag);
                zigzag(root->right,v,level-1,flag);
            }
            else
            {
                zigzag(root->right,v,level-1,flag);
                zigzag(root->left,v,level-1,flag);
            }
        }
        
    }
     int height(TreeNode*root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int ls=height(root->left);
        int rs=height(root->right);
        return max(ls,rs)+1;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int h=height(root);
        vector<vector<int>> v;
        bool flag=true;
        for(int i=1;i<=h;i++)
        {
            vector<int> temp;
            zigzag(root,temp,i,flag);
            v.push_back(temp);
            flag=!flag;
        }
        return v;
    }
};