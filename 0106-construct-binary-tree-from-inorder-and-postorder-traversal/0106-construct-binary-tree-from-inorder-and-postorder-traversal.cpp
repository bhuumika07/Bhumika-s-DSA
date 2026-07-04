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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mpp;
        for(int i=0; i<inorder.size();i++)
        {
            mpp[inorder[i]]=i;
        }
        return buildTree( inorder , 0 , inorder.size()-1 , postorder , 0, postorder.size()-1, mpp );
    }
    TreeNode* buildTree( vector<int>&inorder, int inStart , int inEnd, vector<int>&postorder, int postStart, int postEnd , unordered_map<int,int>&mpp)
    {
        if( inStart > inEnd || postStart > postEnd) return NULL;

        TreeNode* root = new TreeNode( postorder[postEnd]);

        int location = mpp[root->val];
        int onLeft = location - inStart;

        root->left = buildTree(inorder , inStart , location-1, postorder,postStart, postStart+onLeft-1, mpp );
        root->right=buildTree( inorder , location+1, inEnd, postorder, postStart+onLeft, postEnd-1,mpp);
        return root;
    }
};