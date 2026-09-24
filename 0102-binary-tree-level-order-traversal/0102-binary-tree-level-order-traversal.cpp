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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        if(!root) return {};
        q.push(root);
        vector<vector<int>>ans;
        while(!q.empty() && root)
        {
            int s = q.size();
            vector<int>temp;
            for( int i=0; i<s;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if( node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            ans.push_back(temp);
        }
        return ans;
        
    }
};