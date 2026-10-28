class Solution {
public:
    int ans = INT_MAX;
    void dfs(vector<vector<int>>& grid , int xr, int r , int c , vector<vector<vector<bool>>>&visited)
    {
        int n = grid.size();
        int m = grid[0].size();
        int rows[]={1,0};
        int cols[]={0,1};
        xr ^= grid[r][c];
        if( r== n-1 && c == m-1) ans= min( ans , xr);
        if(visited[r][c][xr]) return;
        visited[r][c][xr]=1;
        for( int i =0; i<2; i++)
        {
            int nr = r + rows[i];
            int nc = c + cols[i];
            if( nr >= n || nc >= m) continue;
            dfs(grid , xr , nr , nc , visited);
        }

    }
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<bool>>>visited( 
           n, vector<vector<bool>>(
            m, vector<bool>(1024,0)
           )
        );
        dfs(grid ,0, 0 , 0, visited);
        return ans;
    }
};