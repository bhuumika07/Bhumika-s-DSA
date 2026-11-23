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
      vector< vector<int> > dp( m , vector<int>(n,0));
      for( int i = 0; i<m; i++){
        for( int j =0; j<n; j++){
            if( i == 0|| j == 0) dp[i][j]  = 1;
            else{
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
      }

      return dp[m-1][n-1];


    }
};