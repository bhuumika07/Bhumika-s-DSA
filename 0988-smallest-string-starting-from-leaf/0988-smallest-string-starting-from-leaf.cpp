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
    void solve( TreeNode*root , string str , string &ans)
    {
        if(!root) return;
        if(!root->left &&!root->right)
        {
            str+=char(root->val + 'a');
            reverse(str.begin() , str.end());
            if( ans=="") ans=str;
            if( str < ans) ans=str;
            return;
        }
        str+=char(root->val + 'a');
        solve(root->left , str , ans);
        solve(root->right, str,ans);

    }
    string smallestFromLeaf(TreeNode* root) {
        string str="";
        string ans="";
        solve( root , str , ans);
        return ans;
        
    }
};