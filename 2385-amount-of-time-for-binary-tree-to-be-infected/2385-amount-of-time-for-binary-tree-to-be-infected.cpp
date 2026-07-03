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
    TreeNode* target=NULL;
    void findit( TreeNode* root , int start)
    {
        if( !root || target ) return;
        if( root->val == start)
        {
            target=root;
            return;
        }
        findit( root->left , start);
        findit( root->right, start);
    }

    void markParents( TreeNode* root , unordered_map<TreeNode*, TreeNode*>&mpp, TreeNode* target)
    {
        deque<TreeNode*>dq;
        dq.push_back(root);
        while( !dq.empty())
        {
            int s = dq.size();
            for( int i=0; i<s;i++)
            {
                TreeNode* node = dq.front();
                dq.pop_front();
                if( node-> left)
                {
                    mpp[node->left]=node;
                    dq.push_back( node->left);
                }
                if( node->right)
                {
                    mpp[node->right]=node;
                    dq.push_back(node->right);
                }
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        findit( root , start);
        unordered_map<TreeNode*, TreeNode*>mpp;
        markParents( root , mpp, target);

       
        int count=0;
        deque<TreeNode*>dq;
        dq.push_back(target);
        unordered_map<TreeNode* , bool> visited;
        visited[target]=1;
        TreeNode* node= dq.front();

        while ( !dq.empty() && node )
        {
            int s= dq.size();
            count++;
            for( int i=0; i<s;i++)
            {
                node = dq.front();
                dq.pop_front();
                if( node->left && !visited[node->left])
                {
                    dq.push_back( node->left);
                    visited[node->left]=1;
                    // count++;
                }
                if( node->right && !visited[node->right])
                {
                    dq.push_back( node->right);
                    visited[node->right]=1;
                    // count++;
                }
                if( mpp[node] && !visited[mpp[node]])
                {
                    dq.push_back(mpp[node]);
                    visited[mpp[node]]=1;
                    // count++;
                }
            }
        }
        return count-1;

        
    }
};