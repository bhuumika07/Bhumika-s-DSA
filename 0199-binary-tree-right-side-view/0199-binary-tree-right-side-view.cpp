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
        vector<vector<int>> ans;
        deque<TreeNode*>dq;
        dq.push_back( root );
        while( !dq.empty() && root)
        {
            vector<int>level;
            int size=dq.size();
            for( int i=0; i<size;i++)
            {
                TreeNode* node = dq.front();
                dq.pop_front();
                if( node->left) dq.push_back( node->left);
                if( node->right) dq.push_back( node->right);

                if(!level.empty()) level.pop_back();
                level.push_back(node->val);
            }
            ans.push_back( level);
        }
        vector<int>vals;
        for( int i=0; i< ans.size();i++)
        {
            vals.push_back( ans[i][0]);
        }
        return vals;
        
    }
};