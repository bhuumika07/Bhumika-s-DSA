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
    bool isValidBST(TreeNode* root) {
          return validBST(root, LLONG_MAX, LLONG_MIN);
        
    }
    bool validBST( TreeNode* root , long long maxi , long long mini)
    {
        if(!root) return 1;
        if( root->val >= maxi || root->val <=mini ) return 0;
        return validBST(root->left , root->val , mini) && validBST(root->right , maxi , root->val);
    }
};