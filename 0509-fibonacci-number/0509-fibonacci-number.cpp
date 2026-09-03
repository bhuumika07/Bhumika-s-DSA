class Solution {
public:
    int fib(int n) {
    // for the tabulation solution we start from the edge case itself , is a bottom top approach - opposite to the recursive one which is top to bottom .
    // we start the process for the the edge case itself-- the point where we were stopping before , now we will be starting from their only.
    if(n == 0 || n == 1) return n; 
    vector<int>dp(n+1,-1);
    dp[0]=0;
    dp[1]=1;
    for( int i=2; i<=n;i++)
    {
        dp[i]=dp[i-1] + dp[i-2];
    }
    return dp[n];

        
    }
};