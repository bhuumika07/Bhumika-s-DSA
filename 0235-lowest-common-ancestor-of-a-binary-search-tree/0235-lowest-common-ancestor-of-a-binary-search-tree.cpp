/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans =NULL;
    void CommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(ans) return;
        if(root->val == p->val || root->val == q->val) 
        {
            ans=root;
            return;
        }
       TreeNode* smaller = p->val < q->val ? p : q;
       TreeNode* greater= p->val < q->val ? q : p;
       if( smaller->val < root->val  && greater->val > root->val)
       {
            ans=root;
            return;
       }
       if( smaller->val < root->val && greater->val < root->val)
       {
            CommonAncestor(root->left,p,q);
       }
       if( smaller->val > root->val)
       {
            CommonAncestor(root->right,p,q);
       }
      
    }

     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        CommonAncestor(root,p,q);
        return ans;
     }
};