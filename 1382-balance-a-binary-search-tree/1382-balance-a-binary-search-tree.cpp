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
    void makeArray(TreeNode* root , vector<int>&inorder)
    {
        if(!root) return;
        makeArray(root->left,inorder);
        inorder.push_back(root->val);
        makeArray(root->right, inorder);
    }
    TreeNode* build(vector<int>&inorder , int start , int end)
    {
        if(start > end) return NULL;
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(inorder[mid]);
        root->left=build(inorder , start , mid-1);
        root->right=build( inorder, mid+1, end);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;
        makeArray(root,inorder);
        return build( inorder , 0 , inorder.size()-1);
    }
};