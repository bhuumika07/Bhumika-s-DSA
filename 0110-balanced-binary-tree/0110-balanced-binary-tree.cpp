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
    bool verdict=1;
    int check(TreeNode* root, bool &verdict)
    {
        if(!root || verdict==0) return 0;
        int left = check( root->left, verdict);
        int right = check( root->right , verdict);
        if( abs( left - right) > 1) verdict=0;
        return 1 + max(left , right);
    }
    bool isBalanced(TreeNode* root) {
        bool verdict=1;
        check(root, verdict);
        return verdict;
    }
};