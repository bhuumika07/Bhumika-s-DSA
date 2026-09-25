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
    int maxi = INT_MIN;
    int doit( TreeNode* root)
    {
        if(!root) return 0;
        int left = doit(root->left);
        int right = doit( root->right);
        int current = root->val;
        if(current + left > current ) current+=left;
        if(current + right > current ) current+=right;
        maxi = max( maxi , current);
        if( left < 0 && right < 0) return root->val;
        return root->val + max( left , right);
        // return root->val;
    }
    int maxPathSum(TreeNode* root) {
        doit(root);
        return maxi;
    }
};