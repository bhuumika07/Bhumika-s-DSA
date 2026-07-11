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
    bool isCousins(TreeNode* root, int x, int y) {
        int level=1; 
        unordered_map<int,TreeNode*>mpp;
        deque<TreeNode*>dq;
        dq.push_back(root);

        while( !dq.empty() && root )
        {
            int size = dq.size();
            mpp.clear();
            for( int i=0; i<size; i++)
            {
                TreeNode* node = dq.front();
                dq.pop_front();
                if( node->left) {dq.push_back( node->left);
                mpp[node->left->val]=node;}
                if( node->right) {dq.push_back( node->right);
                 mpp[node->right->val]=node;}
            }
            if( mpp.find(x) != mpp.end() && mpp.find(y)!= mpp.end())
            {
                if( mpp[x] != mpp[y]) return 1;
            }
        }
        return 0;
        
    }
};