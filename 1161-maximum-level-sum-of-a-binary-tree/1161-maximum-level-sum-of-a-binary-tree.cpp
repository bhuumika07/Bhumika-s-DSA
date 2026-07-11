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
    int maxLevelSum(TreeNode* root) {
        int MaxiSum=INT_MIN;
        deque<TreeNode*>dq;
        dq.push_back(root);
        int level=0;
        int ans=0;
        while(!dq.empty() && root)
        {
            int size= dq.size();
            int sum=0;
            for( int i=0; i<size;i++)
            {
                TreeNode* node = dq.front();
                dq.pop_front();
                sum+=node->val;
                if(node->left) dq.push_back(node->left);
                if(node->right) dq.push_back(node->right);
            }
            level++;
            if( MaxiSum < sum)
            {
                ans=level;
                MaxiSum=sum;
            }
            
        }
        return ans;
    }
};