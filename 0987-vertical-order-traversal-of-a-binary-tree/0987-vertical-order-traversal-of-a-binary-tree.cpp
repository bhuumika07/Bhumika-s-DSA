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
    static bool cmp( const pair<int,int> a , const pair<int,int> b)
    {
        if(a.first > b.first) return 0;
        if(a.first == b.first &&  a.second > b.second) return 0;
        return 1;
    }
    void doit( TreeNode* root , int r , int  c ,map< int , vector<pair<int,int> >> &mpp)
    {
        if(!root) return ;
        doit( root->left , r+1, c-1 , mpp);
        doit( root->right , r+1, c+1 , mpp);
        mpp[c].push_back( {r , root->val});
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector< pair<int,int> > >mpp;
        doit( root , 0 , 0 , mpp);
        vector<vector<int>> ans;
        for( auto it : mpp)
        {
            vector<pair<int,int>> arr = it.second;
            sort( arr.begin() , arr.end() , cmp);
            vector<int>temp;
            for( auto i : arr )
            {
                temp.push_back( i.second);
            }
            if(!temp.empty()) ans.push_back( temp );
        }
        return ans;
    }
};