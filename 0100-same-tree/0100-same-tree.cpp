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
    bool checkit(TreeNode* p, TreeNode* q)
    {
        if( p ==NULL && q ==NULL) return 1;
        if(( p==NULL && q!=NULL)|| (p!=NULL && q==NULL)) return 0;
        if( p->val != q->val) return 0;
        bool ver=checkit(p->left,q->left);
        bool ver1=checkit(p->right,q->right);
        return ver && ver1;
        
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
       return checkit(p,q);
        
    }
};