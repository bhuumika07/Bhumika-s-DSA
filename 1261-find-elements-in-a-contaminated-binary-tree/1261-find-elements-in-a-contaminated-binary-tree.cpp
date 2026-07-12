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
class FindElements {
public:
    unordered_set<int>box;
    void makeit( TreeNode* root , int data, unordered_set<int>&box)
    {
        if(!root) return;
        root->val=data;
        box.insert(data);
        makeit(root->left , 2*data+1, box);
        makeit(root->right, 2*data + 2, box);
    }
    FindElements(TreeNode* root) {
        makeit(root,0,box);
    }
    
    bool find(int target) {
        if( box.find( target) != box.end()) return 1;
        return 0;   
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */