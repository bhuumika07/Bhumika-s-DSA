class Solution {
public:
    void doit(vector<vector<int>>&grid ,int r , int c , vector<vector<bool>>&visited)
    {
        int rows[] ={0,-1,0,1};
        int cols[]= {-1,0,1,0};
        int n = grid.size();
        int m = grid[0].size();
        for( int i = 0 ; i<4; i++)
        {
            int nr = rows[i] + r;
            int nc= cols[i] + c;
            if( nr < 0 || nc < 0 || nr >= n || nc>=m) continue;
            if( visited[nr][nc] || grid[nr][nc] == 1) continue;
            visited[nr][nc] = 1;
            doit( grid , nr, nc , visited);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int count  = 0;
        int n= grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(  n, vector<bool>(m,0));
        for( int i = 0; i<n; i++)
        {
            for( int j = 0; j<m; j++)
            {
                if(!visited[i][j] && grid[i][j] == 0 ) 
                {
                    count++;
                    visited[i][j] = 1;
                    doit( grid , i , j, visited);
                }
            }
        }
        visited.assign( n , vector<bool>( m , 0));
        for( int i = 0; i<n;i++)
        {
           for( int j = 0; j<m; j++)
           {
             if(!visited[i][j] && grid[i][j] == 0 && ( i == 0 || j == 0 || i== n-1 || j == m-1))
             {
                count--;
                visited[i][j] = 1;
                doit( grid , i , j, visited);
             } 
           }
        }

        return count;
    }
};