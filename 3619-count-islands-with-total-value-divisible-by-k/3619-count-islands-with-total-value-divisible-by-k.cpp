class Solution {
public:
    long long doit( vector<vector<int>>& grid, int r , int c , vector<vector<bool>>&visited)
    {
        int rows[] = {-1,0,1,0};
        int cols[]=  {0,-1,0,1};
        int n = grid.size();
        int m =grid[0].size();
        long long sum = 0;
        for( int i = 0; i<4; i++)
        {
            int nr = r + rows[i];
            int nc = c + cols[i];
            if( nr < 0 || nc < 0 || nc >=m || nr >= n) continue;
            if(visited[nr][nc] || grid[nr][nc] == 0) continue;
            visited[nr][nc] = 1;
            sum += doit(grid , nr , nc , visited);
        }
        return sum + grid[r][c];
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int count = 0;
        int n = grid.size();
        int m =grid[0].size();
        vector<vector<bool>>visited( n , vector<bool>(m,0));
        for(int i = 0; i<n;i++)
        {
            for( int j = 0; j<m;j++)
            {   
                if(!visited[i][j] && grid[i][j] != 0)
                {
                    visited[i][j]=1;
                    long long sum = doit(grid , i ,j ,visited);
                    if( sum % k  == 0) count++;
                }
            }
        }
        return count;
    }
};