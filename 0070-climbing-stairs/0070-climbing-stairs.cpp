class Solution {
public:
    int dp[46];
    int doit( int n ){
        if( n == 0) return 1;
        if( n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        int one = doit( n-1);
        int two = doit( n-2);

        return dp[n] = one + two;
    }
    int climbStairs(int n) {
        memset(dp , -1 , sizeof(dp));
       return doit(n); 
    }
};