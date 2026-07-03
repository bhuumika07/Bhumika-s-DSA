/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&mpp, TreeNode* target)
    {
        if( !root ) return;
        deque<TreeNode*>dq;
        dq.push_back(root);
        while( !dq.empty() && root)
        {
            int s =dq.size();
            for( int i=0; i<s;i++)
            {
                 TreeNode* node = dq.front();
                 dq.pop_front();
                 if( node->left)
                 {
                    mpp[node->left]=node;
                    dq.push_back( node->left);
                 }
                 if( node->right)
                 {
                    mpp[node->right]=node;
                    dq.push_back( node->right);
                 }

            }
           
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       //firstly i will have all the parent pointers stored in a hash map.
       unordered_map<TreeNode*,TreeNode*>mpp;
       markParents( root , mpp , target);

       deque<TreeNode*>dq;
       unordered_map<TreeNode*, bool> visited;
       visited[target]=true;
       dq.push_back(target);
       int curr=0;
       while( !dq.empty())
       {
        int s = dq.size();
        if( curr++ == k) break;
        for( int i=0; i< s;i++)
        {
            TreeNode* node = dq.front();
            dq.pop_front();
            if( node->left && !visited[node->left])
            {
                dq.push_back( node->left);
                visited[node->left]=1;
            }
            if( node->right && !visited[node->right])
            {
                dq.push_back( node->right);
                visited[node->right]=1;
            }
            if( mpp[node] && !visited[mpp[node]])
            {
                dq.push_back( mpp[node]);
                visited[mpp[node]]=1;
            }
        }
       }

       vector<int>ans;
       while(!dq.empty())
       {
        ans.push_back( dq.front()->val);
        dq.pop_front();
       }
       return ans;
        
    }
};