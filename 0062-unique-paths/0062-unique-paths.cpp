class Solution {
public:
    int dp[101][101];
    int doit( int row , int col , int r ,int c)
    {
        if( row < r || col < c) return 0;
        if(dp[r][c] != -1) return dp[r][c];
        if( row ==r && col==c) return 1;
        int bottom = doit( row , col , r+1 ,c);
        int right = doit(row , col , r , c+1 );

        return dp[r][c]=bottom + right;
    }
    int uniquePaths(int m, int n) {
        memset( dp , -1 , sizeof(dp));
        return doit( m , n , 1 , 1);
    }
};