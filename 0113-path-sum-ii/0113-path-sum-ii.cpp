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
    
    void doit( TreeNode* root , int target , vector<vector<int>>&ans , int sum,vector<int>temp)
    {
        if(!root) return;
        if(!root->left && !root->right)
        {
            sum+=root->val;
            if( sum == target)
            {
                temp.push_back( root->val);
                ans.push_back( temp);
            }   
            return;
        }
        sum+=root->val;
        temp.push_back(root->val);
        doit( root->left , target, ans , sum , temp);
        doit(root->right, target, ans, sum, temp);

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        doit( root , targetSum , ans ,0, temp);
        return ans;
    }
};