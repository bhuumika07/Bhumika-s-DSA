class Solution {
public:
    int dp[71][71][71];
    int doit(vector<vector<int>>&grid , int r1 , int c1 , int c2 )
    {
        int n = grid.size();
        int m = grid[0].size();
        if( c1 < 0 || c2 < 0 || c1 >= m || c2 >= m) return 0;
        int collected = grid[r1][c1];
        if(c1 != c2) collected += grid[r1][c2];
        if( r1 == n-1 ) return dp[r1][c1][c2] = collected;
        if(dp[r1][c1][c2] != -1) return dp[r1][c1][c2];
        int cols[] = {-1, 0 , 1};
        int maxi = 0;
        for( int i = 0; i<3; i++)
        {
            for( int j = 0; j<3; j++)
            {
                int nc1 = c1 + cols[i];
                int nc2 = c2 + cols[j];
                maxi = max( maxi , doit(grid , r1 + 1, nc1 , nc2));
            }
        }
        return dp[r1][c1][c2] = collected + maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int m = grid[0].size();
        return doit(grid ,0,0,m-1);
    }
};