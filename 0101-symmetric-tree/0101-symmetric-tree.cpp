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
    bool solve(TreeNode* node1, TreeNode*node2)
    {
        if(!node1 && !node2) return 1;
        if((node1 && !node2) || (!node1 && node2) ) return 0;
        if(!(solve(node1->left,node2->right))) return 0;
        if(!(solve(node1->right,node2->left))) return 0;
        return ( node1->val == node2->val);
    }
    bool isSymmetric(TreeNode* root) {
    flag=0;
     if(!root) return 0;
     return solve( root->left , root->right);

        
        
        
    }
};