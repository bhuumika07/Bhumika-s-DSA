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
class BSTIterator {
public:
   stack<TreeNode*>st;
   bool reverse=true;
    BSTIterator(TreeNode* root, bool isRev) {
        reverse=isRev;;
        pushVal(root);
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        if(!reverse)pushVal(node->right);
        else pushVal(node->left);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    void pushVal( TreeNode* root)
    {
        TreeNode* curr= root;
        while( curr)
        {
            st.push(curr);
            if(!reverse)curr=curr->left;
            else curr=curr->right;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
       if(!root) return false;
       //next
       BSTIterator l(root,0);
       BSTIterator r(root,1);

       int i=l.next();
       int j=r.next();

       while( i<j)
       {
        if(i+j == k) return 1;
        else if( i+j < k) i=l.next();
        else j=r.next();
       }
       return 0;
        
    }
};