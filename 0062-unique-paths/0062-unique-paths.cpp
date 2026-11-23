class Solution {
public:
    int dp[101][101];
    int doit( int r , int c ){
        if( r < 0 || c < 0) return 0;
        if( r == 0 && c == 0) return 1;
        if(dp[r][c] != -1) return dp[r][c];
        int up = doit(r-1,c);
        int left = doit(r,c-1);
        return dp[r][c] = up+left;
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return doit(m-1,n-1);
    }
};