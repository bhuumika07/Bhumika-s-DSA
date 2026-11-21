class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
       int rows[] = {-1,0,0,1};
       int cols[] ={0,-1,1,0};
       int count = 0;
       queue< pair<int,int>>q;
       for( int i=0; i<n; i++){
        for( int j=0; j<m; j++){
            if(grid[i][j] == 1 )
           { count++;
             if( i==0 || j==0 || i == n-1 || j == m-1){q.push({i,j});grid[i][j] = 0;}}
        }
       }
       while(!q.empty()){
        auto it = q.front(); q.pop();
        int r = it.first;
        int c = it.second;
        grid[r][c] = 0;
        count--;
        for( int i=0; i<4;i++){
            int nr = r + rows[i];
            int nc = c + cols[i];
            if( nr <0 || nc < 0 || nr >=n || nc >= m) continue;
            if(grid[nr][nc] == 0) continue;
            grid[nr][nc] = 0;
            q.push({nr,nc});
        }
       }
        return count;
      
    }
};