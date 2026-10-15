class Solution {
public:
    int dp[50];
    int doit( int n )
    {
        if( n == 0 ) return 1;
        if( n < 0 ) return 0;
        if( dp[n] != -1) return dp[n];
        int take1 = doit(n-1);
        int take2 = doit( n-2);
        return dp[n] = take1+take2; 
    }
    int climbStairs(int n) {
        // so there are 2 steps eveyrtime.
        memset( dp , -1 , sizeof( dp));
        return doit( n );
    }
};