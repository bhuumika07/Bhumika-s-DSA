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
  
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mpp;
        for( int i=0; i<inorder.size();i++)
        {
            mpp[inorder[i]]=i;
        }
        return buildTree( preorder, 0, preorder.size()-1 , inorder , 0, inorder.size()-1, mpp);
    }
      TreeNode* buildTree( vector<int>& preorder, int preStart , int preEnd , vector<int>&inorder, int inStart, int inEnd , unordered_map<int,int>&mpp)
    {
        if( preStart > preEnd || inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode( preorder[preStart]);

        int location = mpp[ root->val];
        int onLeft= location - inStart;

        root->left = buildTree(preorder, preStart+1, preStart+onLeft, inorder, inStart,location-1,mpp);
        root->right= buildTree( preorder, preStart+onLeft+1, preEnd, inorder , location+1, inEnd, mpp);

        return root;
    }
};