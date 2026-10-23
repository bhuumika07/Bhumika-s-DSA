class Solution {
public:
    int doit( vector<vector<int>>&grid , vector<vector<bool>>&visited , int i , int j)
    {
        int n = grid.size();
        int m = grid[0].size();
        visited[i][j] = 1;
        int rows[] = { -1 , 0 , 1 , 0 };
        int cols[] = { 0 , -1 , 0 , 1 };
        int maxi  = 0;
        for( int k = 0; k<4; k++)
        {
            int nrow = i + rows[k];
            int ncol = j + cols[k];
            if( nrow < 0 || ncol < 0 || nrow >= n || ncol >= m) continue;
            if( visited[nrow][ncol] || grid[nrow][ncol] == 0) continue;
            int find = doit( grid , visited , nrow , ncol);
            maxi = max( maxi , find);
        }
        visited[i][j] = 0;
        return maxi + grid[i][j];
        
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi = 0;
        for( int i = 0; i<n; i++)
        {
            for( int j = 0; j<m; j++)
            {
                if( grid[i][j] != 0){
                    vector< vector<bool>> visited( n , vector<bool>( m , 0));
                    int collect = doit( grid , visited, i ,j );
                    maxi = max( maxi , collect );
                }
            }
        }
        return maxi;
        
    }
};