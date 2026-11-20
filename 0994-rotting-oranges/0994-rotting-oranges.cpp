class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // count fresh oranges beforehand
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        queue< pair<int,int> > q;
        vector< vector<bool>> visited( n , vector<bool>(m,0));
        for( int i= 0; i<n;i++){
            for( int j=0; j<m;j++){
                if(grid[i][j] == 1) count++;
                if(grid[i][j] == 2) {q.push({i,j});
                visited[i][j] = 1;}
            }
        }

        int rows[] = {-1,0,1,0};
        int cols[] = {0,-1,0,1};
        int khrab = 0;
        int time = 0;
        while(!q.empty()){
            int size = q.size();
            bool did = 0;
            for( int i = 0; i<size; i++){
                auto it = q.front();
                q.pop();
                int r = it.first;
                int c = it.second;
                if(grid[r][c] == 1) {
                    khrab++;
                }
                for( int j=0; j<4; j++){
                    int nr = rows[j] + r;
                    int nc = cols[j] + c;
                    if( nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                    if(!visited[nr][nc] && grid[nr][nc] == 1){
                        // grid[nr][nc] = 2;
                        visited[nr][nc] = 1;
                        q.push({nr,nc});
                        did = 1;
                    }
                }
            }
           if(did) time++;
        }
        if( khrab == count) return time;
        return -1;

       
    }
};