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

    int countNodes(TreeNode* root) {
        deque<TreeNode*>dq;
        int count=0;
        dq.push_back( root );
        while( !dq.empty() && root )
        {
            int s= dq.size();
            for( int i=0; i<s;i++)
            {
                count++;
                TreeNode* node = dq.front();
                dq.pop_front();
                if( node->left) dq.push_back(node->left);
                if( node->right) dq.push_back( node->right);
            }
        }
        return count;
        
    }
};