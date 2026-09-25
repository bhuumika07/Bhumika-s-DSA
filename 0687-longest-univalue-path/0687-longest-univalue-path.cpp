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
    int maxlen = 0;
    int doit( TreeNode* root)
    {
        if(!root) return 0;
        int left = doit(root->left);
        int right = doit(root->right);
        int curr = 0;
        if( root->left && root->left->val == root->val) curr+=left;
        if(root->right && root->right->val == root->val) curr+=right;

        maxlen = max( maxlen , curr);

        if((root->left && root->left->val == root->val) && ( root->right && root->right->val == root->val)) return 1 + max( left , right);

        if(root->left && root->left->val==root->val) return 1 + left;
        if( root->right && root->right->val == root->val) return 1 + right;
        return 1;
    }
    int longestUnivaluePath(TreeNode* root) {
        doit(root);
        return maxlen;
    }
};