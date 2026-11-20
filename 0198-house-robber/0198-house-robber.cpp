class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,0);
        dp[0] = nums[0];
        for( int i = 1; i<n; i++){
            dp[i] = nums[i];

            if( i > 1) dp[i] += dp[i-2];

            dp[i] = max(dp[i] , dp[i-1]);
        }

        return dp[n-1];
    }
};