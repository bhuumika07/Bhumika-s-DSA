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
    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<int , TreeNode*>mpp;
        deque<TreeNode*>dq;
        dq.push_back( root );
        vector<int>levels;
        int sum=0;
        while(!dq.empty() && root )
        {
           int s = dq.size();
           sum=0;
           for( int i=0; i<s;i++)
           {
            TreeNode* node = dq.front();
            dq.pop_front();
            sum+=node->val;
            if( node->left)dq.push_back( node->left);
            if(node->right)dq.push_back(node->right);
           }
           levels.push_back(sum);
        }

        int depth=1;
        root->val=0;
        dq.push_back(root);
        while( !dq.empty() && root)
        {
            int s =dq.size();
            for( int i=0; i<s; i++)
            {
                TreeNode* node = dq.front();
                dq.pop_front();
                long long childSum=0;

                if( node->left)childSum+=node->left->val;
                if(node->right) childSum+=node->right->val;

                if(node->left)
                {
                    node->left->val = levels[depth]-childSum;
                    dq.push_back(node->left);
                }
                if( node->right)
                {
                    node->right->val= levels[depth]-childSum;
                    dq.push_back(node->right);
                }
            }
            depth++;
        }
        return root;

        
    }
};