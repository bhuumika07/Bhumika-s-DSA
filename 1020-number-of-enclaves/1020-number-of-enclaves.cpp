class Solution {
public:
    int markem( vector<vector<int>>&grid , vector<vector<bool>>&visited, int r , int c){
       int n = grid.size();
       int m = grid[0].size();
       int rows[] = {-1,0,1,0};
       int cols[] ={0,-1,0,1};
       int count = 1;
       visited[r][c] = 1;
       for( int i = 0; i<4; i++){
        int nr = r + rows[i];
        int nc = c + cols[i];
        if( nr <0 || nc < 0 || nr >= n || nc >= m) continue;
        if(grid[nr][nc] && !visited[nr][nc] ) {visited[nr][nc] = 1;count+= markem( grid , visited , nr , nc);}
        
       } 
       return count ;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        for( int i= 0 ; i<n; i++){
            for( int j =0; j<m; j++){
                if(grid[i][j]) count++;
            }
        }
        vector< vector<bool>> visited( n , vector<bool>(m,0));
        for( int i= 0 ; i<n; i++){
            for( int j =0; j<m; j++){
                if( grid[i][j] == 1 && !visited[i][j])
                {
                    if( i == 0 || j ==0 || i == n-1 || j == m-1){
                        count -= markem(grid , visited ,i ,j) ;
                    }
                }
            }
        }
        return count;
    }
};