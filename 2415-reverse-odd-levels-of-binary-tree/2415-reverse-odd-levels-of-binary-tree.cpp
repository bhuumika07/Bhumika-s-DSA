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
    void dfs(TreeNode* leftptr , TreeNode* rightptr , int level)
    {
        if(!leftptr || !rightptr) return;

        if(level%2!=0)swap(leftptr->val ,rightptr->val);
        dfs( leftptr->left , rightptr->right , level+1);
        dfs(leftptr->right, rightptr->left, level+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return nullptr;

        dfs(root->left , root->right , 1);
        
        return root;
    }
};