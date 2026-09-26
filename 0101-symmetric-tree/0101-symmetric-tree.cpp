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
    bool doit( TreeNode* p , TreeNode* q)
    {
        if(p && !q) return 0;
        if(!p && q) return 0;
        if(!p && !q) return 1;
        if( p->val != q->val) return 0;
        return (doit(p->left , q->right) && doit(p->right , q->left));
    }
    bool isSymmetric(TreeNode* root) {
        return doit( root->left , root->right);
        
    }
};