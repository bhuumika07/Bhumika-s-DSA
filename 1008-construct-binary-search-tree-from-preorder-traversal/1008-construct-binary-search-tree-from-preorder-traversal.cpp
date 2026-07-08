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
    void makeit( TreeNode* root , int num)
    {
        TreeNode* curr = root;
        TreeNode* next = new TreeNode(num);
        while( curr )
        {
            if( curr->val > num)
            {
                if(curr->left)
                {
                    curr=curr->left;
                }
                else
                {
                    curr->left=next;
                    break;
                }
            }
            else
            {
                if( curr->right) curr=curr->right;
                else
                {
                    curr->right=next;
                    break;
                }
            }
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        for( int i=1; i<preorder.size(); i++)
        {
            makeit(root, preorder[i]);
        }
        return root;
    }
};