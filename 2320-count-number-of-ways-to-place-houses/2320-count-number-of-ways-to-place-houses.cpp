class Solution {
public:
long long dp[10005];
long long  mod = 1e9 + 7;
    int countHousePlacements(int n) {
        memset( dp , -1, sizeof(dp));
        dp[0]=1;
        dp[1] = 2;
        for( int i=2; i<=n;i++)
        {
            dp[i] = (dp[i-1] + dp[i-2]) % mod;
        }
        return (dp[n]*dp[n])%mod;
    }
};