class Solution {
public:
    int climbStairs(int n) {
      // tabulation will be written from the base case --> that is from 0.
      // what are the possible ways to become 0 or 1--> 1- right
      // i will always fetch out last 2 values to get what i want to achieve.
      vector<int>dp(n+1,0);
      dp[0] = 1;
      dp[1] = 1;
      for( int i=2; i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
      }
      return dp[n];
    }
};