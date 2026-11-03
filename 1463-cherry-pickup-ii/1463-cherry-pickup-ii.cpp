class Solution {
public:
    int dp[71][71][71];
    int doit(vector<vector<int>>&grid , int r , int c1 , int c2)
    {
        int m = grid[0].size();
        int n = grid.size();
        if( c1 >= m || c2 >= m || c1 < 0 || c2 < 0) return 0;
        int collected = grid[r][c1];
        if(c1 != c2) collected += grid[r][c2];
        if( r == n-1) return collected;
        if(dp[r][c1][c2] != -1) return dp[r][c1][c2];
        int cols[] = { -1 , 0 , 1};
        int maxi = 0;
        for(int i=0; i<3;i++){
            for(int j=0;j<3;j++)
         {   int nc1= cols[i] + c1;
            int nc2 = cols[j] + c2;
            maxi = max( maxi , doit(grid,r+1,nc1,nc2));}
        }
        return dp[r][c1][c2] = collected+maxi;

    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return doit(grid,0,0,grid[0].size()-1);
        
    }
};