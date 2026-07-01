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
    void solve(TreeNode*root, TreeNode* parent , TreeNode* grandparent, int&ans)
    {
        if( !root )return;
        if(grandparent && grandparent->val%2==0) ans+=root->val;

        solve(root->left, root, parent,ans);
        solve( root->right, root, parent,ans); 
    }
    int sumEvenGrandparent(TreeNode* root) {
        int ans=0;
        solve(root,NULL,NULL,ans);
        return ans;
        
    }
};