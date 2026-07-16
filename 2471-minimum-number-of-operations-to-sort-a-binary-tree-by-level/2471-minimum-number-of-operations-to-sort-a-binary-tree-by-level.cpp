class Solution {
public:

    int minSwaps(vector<int>& nums)
    {
        int n = nums.size();

        vector<pair<int,int>> v;

        for(int i=0;i<n;i++)
            v.push_back({nums[i],i});

        sort(v.begin(),v.end());

        vector<bool> vis(n,false);

        int swaps=0;

        for(int i=0;i<n;i++)
        {
            if(vis[i] || v[i].second==i)
                continue;

            int cycle=0;
            int j=i;

            while(!vis[j])
            {
                vis[j]=true;
                j=v[j].second;
                cycle++;
            }

            swaps+=cycle-1;
        }

        return swaps;
    }

    int minimumOperations(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);

        int ans=0;

        while(!q.empty())
        {
            int sz=q.size();

            vector<int> level;

            while(sz--)
            {
                TreeNode* node=q.front();
                q.pop();

                level.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            ans+=minSwaps(level);
        }

        return ans;
    }
};