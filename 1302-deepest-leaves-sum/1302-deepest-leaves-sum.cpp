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
    int deepestLeavesSum(TreeNode* root) {
        if( !root ) return 0;
        vector<vector<int>>ans;
        deque<TreeNode*>dq;
        dq.push_back(root);

        while( !dq.empty() && root)
        {
            vector<int>level;
            int size= dq.size();
            for( int i=0; i<size;i++)
            {
                TreeNode* node = dq.front();
                dq.pop_front();
                if( node->left) dq.push_back(node->left);
                if( node->right) dq.push_back(node->right);
                level.push_back( node->val);
            }
           if(!ans.empty()) ans.pop_back();
            ans.push_back( level);
        }
        int s= ans.size();
        vector<int>arr= ans[s-1];
        int sum=0;
        for( int n : arr)
        {
            sum+=n;
        }
        return sum;
       
        
    }
};