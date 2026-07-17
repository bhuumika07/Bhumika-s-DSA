class Solution {
public:
    struct Info {
        bool isBST;
        int sum;
        int mini;
        int maxi;

        Info(bool b, int s, int mn, int mx)
            : isBST(b), sum(s), mini(mn), maxi(mx) {}
    };

    int ans = 0;

    Info solve(TreeNode* root) {
        if (!root)
            return Info(true, 0, INT_MAX, INT_MIN);

        Info left = solve(root->left);
        Info right = solve(root->right);

        // Check if current subtree is a BST
        if (left.isBST && right.isBST &&
            root->val > left.maxi &&
            root->val < right.mini) {

            int currSum = left.sum + right.sum + root->val;
            ans = max(ans, currSum);

            int currMin = min(root->val, left.mini);
            int currMax = max(root->val, right.maxi);

            return Info(true, currSum, currMin, currMax);
        }

        // Current subtree is not a BST
        return Info(false, 0, 0, 0);
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};