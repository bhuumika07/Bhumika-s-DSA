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
TreeNode* prev=NULL;
TreeNode* first=NULL;
TreeNode* last=NULL;
TreeNode* middle=NULL;
    void doit( TreeNode* root)
    {
        if(!root) return;
        doit(root->left);
        if(prev != NULL && root->val < prev->val)
        {
            if( first == NULL)
            {
                first=prev;
                middle=root;
            }
            else last=root;
        }
        prev=root;
        doit( root->right);
    }
    void recoverTree(TreeNode* root) {
        doit(root);
        if( first && last) swap( first->val , last->val);
        else if( first && middle ) swap(first->val, middle->val);
        
    }
};