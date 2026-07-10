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
    int findBottomLeftValue(TreeNode* root) {
        if(!root) return 0;
        deque<TreeNode*>dq;
        dq.push_back(root);
        int last=root->val;
        while(!dq.empty())
        {
            int size=dq.size();
            for( int i=0; i<size;i++)
            {
                TreeNode* node=dq.front();
                dq.pop_front();
                if(i==0) last = node->val;
                if(node->left) dq.push_back(node->left);
                if(node->right) dq.push_back(node->right);
            }
        }
        return last;
    }
};