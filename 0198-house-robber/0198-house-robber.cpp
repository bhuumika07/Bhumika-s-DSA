class Solution {
public:
    int rob(vector<int>& nums) {
       int n = nums.size();
       vector<int>dp(n,0);
       dp[0] = nums[0];
       for( int i = 1; i<n; i++){
        dp[i] = dp[i-1]; // i will not loot thid house and will just take whatever i have lotted till now.

        // what if i do loot this house and pick the max.
        if(i > 1) dp[i] = max(dp[i] , dp[i-2] + nums[i]);
        else dp[i] = max(dp[i] , nums[i]);
       }
       return dp[n-1];
    }
};