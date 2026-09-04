class Solution {
public:
    int rows[4]={-1,0,1,0};
    int cols[4]={0,-1,0,1};
   
    bool markit( vector<vector<int>>&grid , int r , int c ,vector<vector<bool>>&visited)
    {   
        int rsize = grid.size();
        int csize = grid[0].size();
        queue<pair<int,int>>q;
        visited[r][c]=1;
        q.push({r,c});
        bool verdict=1;
        if( r == 0 || c==0 || r == rsize-1 || c == csize-1) verdict=0;
        while(!q.empty())
        {
            auto [r1,c1] = q.front();
            q.pop();

            for( int i=0;i<4;i++)
            {
                int nrow = rows[i] + r1;
                int ncol = cols[i] + c1;
                if( nrow >= 0 && nrow < rsize && ncol >=0 && ncol < csize && !visited[nrow][ncol] && grid[nrow][ncol]==0)
                {
                    if( nrow == 0 || ncol ==0 || nrow == rsize-1 || ncol == csize-1) verdict=0;
                    visited[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
        return verdict;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int rsize = grid.size();
        int csize = grid[0].size();
      
        vector<vector<bool>>visited(rsize, vector<bool>(csize,0));
        
        int count=0;
        for( int i=0; i<rsize; i++)
        {
            for( int j=0; j<csize; j++)
            {
                if(grid[i][j]==0 && !visited[i][j])
                {
                    visited[i][j]=1;
                    if(markit( grid ,i,j,visited)) count++;
                }
            }
        }
       return count;
    }
};