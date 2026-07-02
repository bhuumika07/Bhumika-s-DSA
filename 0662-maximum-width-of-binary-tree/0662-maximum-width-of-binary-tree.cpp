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
    int widthOfBinaryTree(TreeNode* root) {
      deque<pair<TreeNode*,long long>>dq;
      dq.push_back({root,0});
      int width=0;
      while( !dq.empty() && root )
      {
        int size= dq.size();
        int mini=dq.front().second;

        int first = dq.front().second;
        int last = dq.back().second;
        width = max(width, last - first + 1);

        for( int i=0; i<size;i++)
        {
            TreeNode* node = dq.front().first;
            int index= dq.front().second - mini;
            dq.pop_front();
            if( node->left) dq.push_back({node->left, 1LL*2*index + 1});
            if( node->right) dq.push_back({node->right, 1LL*2*index + 2});
        }
       
      }
      return width;
    }
};