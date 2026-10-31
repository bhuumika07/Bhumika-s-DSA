class Solution {
public:
    int dp[501][501][2];
    // direction =>1 = right ; direction => 0 = down.
    int mod = 1e9 + 7;
    long long count  = 0;
    int doit(vector<vector<int>>&grid , int r , int c, int direction)
    {
        int n = grid.size();
        int m = grid[0].size();
        if( r >= n || c >= m) return 0;
        if(r==n-1 && c==m-1) return 1;
        if(dp[r][c][direction] != -1) return dp[r][c][direction];
        long long ans = 0;
        if(grid[r][c] == 0)
        {
            ans += doit(grid , r+1 ,c ,0);
            ans += doit(grid , r , c+1 , 1);
        }
        else {
            if(direction == 1)
            {
                ans += doit( grid , r+1 ,c , 0);
            }
            else ans += doit( grid , r , c+1,1);
        }
        return dp[r][c][direction] = ans%mod;
        
    }
    int uniquePaths(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return doit(grid,0,0,0);
    
    }
};