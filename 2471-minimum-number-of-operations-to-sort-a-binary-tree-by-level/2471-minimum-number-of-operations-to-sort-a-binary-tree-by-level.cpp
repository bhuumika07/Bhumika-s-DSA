class Solution {
public:

    int minSwaps(vector<int>& nums)
{
    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.end());

    unordered_map<int,int> pos;

    for(int i=0;i<nums.size();i++)
        pos[nums[i]] = i;

    int swaps = 0;

    for(int i=0;i<nums.size();i++)
    {
        if(nums[i] == sorted[i])
            continue;

        swaps++;

        int idx = pos[sorted[i]];

        pos[nums[i]] = idx;
        pos[sorted[i]] = i;

        swap(nums[i], nums[idx]);
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