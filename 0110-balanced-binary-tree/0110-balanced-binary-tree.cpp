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
    bool flag=1;
    int length(TreeNode* root)
    {
        if( !root ) return 0;
        int left = length( root->left);
        int right= length( root->right);
        int diff = abs(right - left) ;
        if( diff > 1) flag=0;
        return 1 +max( left, right);

    }
    bool isBalanced(TreeNode* root) {
        length(root);
        return flag;

        
    }
};