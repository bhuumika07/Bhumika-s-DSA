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
    static bool cmp(pair<int,int>a, pair<int,int>b)
    {
        if( a.first > b.first) return 0;
        if(a.first == b.first && a.second > b.second) return 0;
        return 1;
    }
    void solve(TreeNode*root, int row, int col ,map<int,vector<pair<int,int>>>&mpp)
    {
        if( root==NULL) return;
        solve( root->left, row+1, col-1, mpp);
        solve(root->right, row+1, col+1,mpp);
        mpp[col].push_back({row,root->val});
    }


    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        map<int,vector<pair<int,int>>>mpp;
        solve(root, 0,0,mpp);
        vector<vector<int>> ans;
        for( auto it : mpp)
        {
            vector<pair<int,int>> arr=it.second;
            sort(arr.begin(), arr.end(), cmp);
            vector<int>temp;
            for( int i=0; i<arr.size();i++)
            {
                temp.push_back(arr[i].second);
            }
            ans.push_back(temp);
        }
        return ans;
        
       
    }
};