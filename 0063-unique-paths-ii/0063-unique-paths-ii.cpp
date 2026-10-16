class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        // tabulation approach
        int n = grid.size()-1;
        int m = grid[0].size()-1;
        if(grid[0][0] == 1 || grid[n][m] == 1) return 0;
        vector<vector<int>>dp( n+1 , vector<int>(m+1 , 0));
        dp[0][0] = 1;
        for( int i=0; i<=n; i++)
        {
            for( int j=0; j<=m ; j++)
            {
                if(i==0 && j == 0) continue;
                if( i > 0 && grid[i-1][j] != 1) dp[i][j] = dp[i-1][j];
                if( j > 0 && grid[i][j-1] != 1) dp[i][j] += dp[i][j-1];
            }
        }
        return dp[n][m];
    }
};