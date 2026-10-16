class Solution {
public:
    int dp[101][101];
    int doit( int n , int m)
    {
        if( n == 0 && m == 0) return 1;
        if( n < 0 || m < 0) return 0;
        if( dp[n][m] != -1) return dp[n][m];
        int down = doit( n-1 , m);
        int right = doit(n , m-1);

        return dp[n][m] = down + right;
    }
    int uniquePaths(int m, int n) {
        // down --> i+1 , right --> j+1
        int rows[] = {0,1};
        int cols[] ={1,0};
        memset(dp , -1 , sizeof(dp));
        return doit(m-1,n-1);
    }
};