class Solution {
public:
    int dp[10005];
    int doit( int total )
    {
        if( total == 0) return 0;
        if(dp[total] != -1) return dp[total];
        int ans=INT_MAX;
        for( int i = 1; i*i <= total ; i++)
        {
            int temp = doit( total - i*i);
            if(temp!=INT_MAX) ans = min( ans , temp+1);
        }
        return dp[total] = ans;
    }
    int numSquares(int n) {
        if( n==1) return 1;
        memset( dp , -1, sizeof(dp));
        return doit(n);
    }
};