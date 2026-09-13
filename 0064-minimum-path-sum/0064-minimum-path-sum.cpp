class Solution {
public:
    int dp[201][201];
    int doit( vector<vector<int>>&grid , int r , int c)
    {
        if( r >= grid.size() || c >= grid[0].size()) return INT_MAX;
        if(dp[r][c] != -1) return dp[r][c];
        if( r == grid.size() -1 && c== grid[0].size()-1) return grid[r][c];
        int right = doit(grid , r , c+1);
        if( right!= INT_MAX) right +=grid[r][c];
        int down = doit( grid , r+1 , c);
        if( down != INT_MAX) down += grid[r][c];

        return dp[r][c] = min( right , down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset( dp , -1 , sizeof(dp));
        return doit( grid , 0 , 0);
        
    }
};