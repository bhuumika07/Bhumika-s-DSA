class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue< tuple<int,int,int>> q;
        vector<vector<bool>> visited( n , vector<bool>( m , 0));
        vector<vector<int>>ans( n , vector<int>( m , 0));
        for( int i =0; i<n;i++){
            for( int j=0; j<m;j++){
                if(mat[i][j] == 0) q.push( {i,j,0});
            }
        }
        int rows[] =  {-1,0,1,0};
        int cols[] ={0,-1,0,1};
       
       while(!q.empty()){
        auto [ r, c , dis] = q.front();
        q.pop();
        for( int i = 0; i<4; i++){
            int nr = r + rows[i];
            int nc = c + cols[i];

            if( nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if( visited[nr][nc] || mat[nr][nc] == 0) continue;
            ans[nr][nc] = dis + 1;
            visited[nr][nc] = 1;
            q.push({nr , nc, dis+1});
        }
       }
       return ans;
    }

};