class Solution {
public:
    long long dp[105][105];
    long long doit( vector<vector<int>>& grid , int r , int c )
    {
        if(r >= grid.size() || c >= grid[0].size()) return 0;
        if( grid[r][c] == 1) return 0;
        if(dp[r][c] != -1) return dp[r][c];
        if(r == grid.size()-1 && c == grid[0].size()-1) return 1;

        long long right = doit( grid , r, c+1);
        long long bottom = doit( grid , r+1 , c);

        return dp[r][c] = ( right + bottom);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        memset( dp , -1 , sizeof(dp));
         return doit( grid , 0 , 0);
        
    }
};