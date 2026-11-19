class Solution {
public:
    void markit( vector<vector<char>>& grid , vector<vector<bool>>&visited , int r ,int c){
        int n = grid.size();
        int m = grid[0].size();
        if( r <0 || c < 0 || r >= n || c >= m) return;
        visited[r][c] = 1;
        int rows[] = {0 , -1 , 1 , 0};
        int cols[] ={ -1  , 0 , 0 , 1};
        for( int i = 0; i<4; i++){
            int nr = rows[i] + r;
            int nc = cols[i] + c;
            if( nr <0 || nc < 0 || nr >= n || nc >= m)continue;
            if(!visited[nr][nc] && grid[nr][nc] == '1'){
                markit(grid,visited,nr,nc);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // it is of BFS.
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<bool>>visited( n , vector<bool>(m , 0));
        for( int i=0; i<n; i++){
            for( int j=0;j<m; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    count++;
                    markit( grid , visited , i , j);
                }
            }
        }
        return count;
    }
};