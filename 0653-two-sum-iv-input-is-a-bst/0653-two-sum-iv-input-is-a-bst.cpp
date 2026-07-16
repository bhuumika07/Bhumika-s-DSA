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
    bool verdict=0;
    void solve(TreeNode* root, unordered_map<int,int>&mpp, int target)
    {
     if(!root || verdict) return;   
     int req= target - root->val;
     if( mpp.find(req) != mpp.end())
     {
        verdict=1;
        return;
     }
     mpp[root->val]++;
     solve(root->left,mpp,target);
     solve(root->right,mpp,target);
     
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int>mpp;
        solve(root,mpp,k);
        return verdict;
        
    }
};