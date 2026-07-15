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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        deque<TreeNode*>dq;
        dq.push_back(root);
        while(!dq.empty() && root != NULL)
        {
            vector<int>level;
            int size = dq.size();
            for( int i=0; i<size;i++)
            {
                TreeNode* node = dq.front();
                dq.pop_front();
                if( node->left != NULL) dq.push_back( node->left);
                if( node->right != NULL) dq.push_back( node->right);
                level.push_back( node->val);
            }
            ans.push_back(level);
        }
        reverse( ans.begin() , ans.end());
        return ans;
        
    }
};