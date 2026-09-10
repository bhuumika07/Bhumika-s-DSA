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
    int ans=0;
    pair<int,int> doit( TreeNode* root)
    {
        if( root == NULL) return {0,0};
        auto [leftlen, leftvalue ] = doit(root->left);
        auto  [rightlen, rightvalue] = doit( root->right);
        int total = leftlen + rightlen + 1;
        int avgSum = leftvalue + rightvalue + root->val;
        if( avgSum / total == root->val ) ans++;
        return {total,avgSum};
       
    }
    int averageOfSubtree(TreeNode* root) {
        doit(root);
        return ans;
    }
};