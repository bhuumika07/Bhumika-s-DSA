class Solution {
public:
    int dp[101][101];
    int doit( vector<vector<int>>&grid , int n , int m)
    { 
        if( n == 0 && m == 0 && grid[n][m] != 1) return 1;
        if( n < 0 || m < 0) return 0;
        if( dp[n][m] != -1) return dp[n][m];
        if( grid[n][m] == 1) return 0;
        int right = doit( grid , n, m-1);
        int down = doit( grid , n-1 , m);
        return dp[n][m] = right+ down;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        memset(dp , -1 , sizeof(dp));
        int n = grid.size()-1;
        int m = grid[0].size()-1;
        return doit( grid  , n , m);
    }
};