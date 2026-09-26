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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*>q;
        vector<int>ans;
        q.push(root);
        while(!q.empty())
        {
            int lastNode = -200;
            int size = q.size();
            for( int i=0; i<size;i++)
            {
                TreeNode* node = q.front();
                lastNode = node->val;
                q.pop();
                if( node->left) q.push( node->left);
                if( node->right) q.push( node->right);
            }
            ans.push_back( lastNode);
        }
        return ans;
        
    }
};