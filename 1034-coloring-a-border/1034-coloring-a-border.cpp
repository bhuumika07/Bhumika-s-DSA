class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        queue<pair<int,int>>q;
        int rsize = grid.size();
        int csize=grid[0].size();
        int rows[]={0,-1,1,0};
        int cols[]={-1,0,0,1};
        vector<vector<bool>>visited(rsize , vector<bool>( csize , false));
        vector<vector<int>>ans(rsize,vector<int>(csize,0));
        ans=grid;
        q.push({row,col});
        int c = grid[row][col];
        visited[row][col]=1;
        if( row == 0 || col == 0 || row == rsize-1 || col == csize-1) ans[row][col]=color;
        while(!q.empty())
        {
            int r1=q.front().first;
            int c1=q.front().second;
            q.pop();
            int count=0;
            for( int i=0; i<4;i++)
            {
                int nrow = r1+rows[i];
                int ncol = c1+ cols[i];
                if( nrow >=0 && nrow < rsize && ncol >=0 && ncol< csize && grid[nrow][ncol] == c)
                {
                   count++;
                } 
            }
            if( count < 4) ans[r1][c1]=color;
            for( int i=0; i<4;i++)
            {
                int nrow = r1+rows[i];
                int ncol = c1+ cols[i];
                if( nrow >=0 && nrow < rsize && ncol >=0 && ncol< csize && grid[nrow][ncol] == c && !visited[nrow][ncol])
                {
                    visited[nrow][ncol]=1;
                    q.push({nrow,ncol});
                } 
            }

        }
        return ans;
        
    }
};