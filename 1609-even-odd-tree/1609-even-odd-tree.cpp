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
    bool isEvenOddTree(TreeNode* root) {
        int count =0;
        if( root->val % 2==0) return 0;
        deque<TreeNode*>dq;
        dq.push_back(root);

        while( ! dq.empty() && root)
        {
            int last=-1;
            int s = dq.size();
            for( int i=0; i<s;i++)
            {
                TreeNode* node = dq.front();
                dq.pop_front();
                if( count % 2 == 0)
                {
                    if(node->val %2 ==0 ) return 0;
                    if( last != -1 && last >= node->val) return 0;
                    last=node->val;
                } 
                else
                {
                    if( node->val % 2 !=0) return 0;
                    if( last != -1 && last <= node->val) return 0;
                    last=node->val;
                }
                if(node->left) dq.push_back( node->left);
                if( node->right) dq.push_back( node->right);
            }
            count++;
        }
        return 1;
        
    }
};