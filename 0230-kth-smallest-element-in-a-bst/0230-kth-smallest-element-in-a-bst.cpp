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
int ans = -1;
    void callMe( TreeNode* root , int& count , int k)
    {
        if( !root || ans != -1) return ;
        callMe(root->left , count , k);
        count++;
        if( count == k)
        {
            ans=root->val;
            return;
        }
       callMe( root->right , count , k);
    }
    int kthSmallest(TreeNode* root, int k) {
       int count=0;
        callMe(root,count,k);
        return ans;
        
    }
};