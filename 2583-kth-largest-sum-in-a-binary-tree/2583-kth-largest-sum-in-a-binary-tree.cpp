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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> ans;
        long long sum=0;
        deque<TreeNode*>dq;
        dq.push_back(root);

        while(!dq.empty() && root)
        {
            int s= dq.size();
            sum=0;
            for( int i=0; i<s;i++)
            {
                TreeNode* node = dq.front();
                dq.pop_front();
                sum+=node->val;
                if(node->left) dq.push_back( node->left);
                if(node->right) dq.push_back( node->right);
            }
            ans.push_back(sum);
        }
        if( k-1 >= ans.size()) return -1;
        sort(ans.begin(), ans.end(), greater<long long>());
        return ans[k-1];
        
    }
};