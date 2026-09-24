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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        TreeNode* curr = root;
        vector<int>ans;
        TreeNode* lastVisited = NULL;
        while( curr || !st.empty())
        {
            while( curr )
            {
                st.push( curr);
                curr = curr->left;
            }
            // when it no longer can 
            TreeNode* node = st.top();
            if( node->right && lastVisited != node->right) curr = node->right;
            else 
            {
                ans.push_back( node->val);
                st.pop();
                lastVisited = node;
            }
        }
        return ans;
    }
};