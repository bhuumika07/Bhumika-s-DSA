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
    void getit( TreeNode* root , vector<int>&inorder)
    {
        if(!root) return;
        getit(root->left, inorder);
        inorder.push_back(root->val);
        getit(root->right,inorder);
    }
    void fixit( TreeNode* root , vector<int>&inorder , int &idx)
    {
        if(!root || idx==inorder.size()) return;
        fixit(root->left,inorder,idx);
        root->val = inorder[idx++];
        fixit(root->right, inorder,idx);

    }
    void recoverTree(TreeNode* root) {
        vector<int>inorder;
        getit(root,inorder);
        sort(inorder.begin() , inorder.end());
        int idx=0;
        fixit(root,inorder,idx);
        
    }
};