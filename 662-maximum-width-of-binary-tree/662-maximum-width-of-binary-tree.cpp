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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int ans=0;
        while(!q.empty())
        {
            int l=q.size();
            int curr_min=q.front().second;
             int start,last;
            for(int i=0;i<l;i++)
            {
                long long curr=q.front().second-curr_min;
                TreeNode*temp=q.front().first;
                q.pop();
                if(i==0)
                {
                    start=curr;
                }
                if(i==l-1)
                {
                    last=curr;
                }
                if(temp->left)
                {
                    q.push({temp->left,curr*2+1});
                }
                if(temp->right)
                {
                    q.push({temp->right,curr*2+2});
                }
            }
            ans=max(ans,last-start+1);
        }
        return ans;
    }
};