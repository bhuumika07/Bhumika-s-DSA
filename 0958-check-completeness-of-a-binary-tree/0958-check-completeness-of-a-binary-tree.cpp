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
    bool isCompleteTree(TreeNode* root) {
        deque<TreeNode*>dq;
        dq.push_back(root);
         bool seen=0;
        while( !dq.empty() && root)
        {
            int s= dq.size();
           
            for( int i=0; i<s;i++)
            {
                TreeNode* node = dq.front();
                dq.pop_front();
              if (node->left) {
              if (seen) return false;
              dq.push_back(node->left);
            }
             else {
            seen = true;
            }

            if (node->right) {
            if (seen) return false;
            dq.push_back(node->right);
            }
             else {
            seen = true;
            }
            }
        }
        return 1;

        
    }
};