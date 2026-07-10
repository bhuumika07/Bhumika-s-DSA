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

    void solve(TreeNode* root , int maxi , int mini, int&diff)
    {
        if(!root) return;
        maxi=max( maxi , root->val);
        mini= min(mini , root->val);
        diff=max(diff, abs(maxi-mini));
        solve(root->left , maxi,mini,diff);
        solve(root->right,maxi,mini,diff);
    }
    int maxAncestorDiff(TreeNode* root) {
     if( !root ) return 0;
     int diff=0;
     int maxi=root->val;
     int mini = maxi;
     solve(root , maxi , mini , diff);   
     return diff;
    }
};