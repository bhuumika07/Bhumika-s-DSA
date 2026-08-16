class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int csize = grid[0].size();
        int rsize = grid.size();
        int r=0; int c=0;
        int rows[]={0,-1,0,1};
        int cols[]={-1,0,1,0};
        vector<vector<bool>>visited(rsize , vector<bool>( csize , 0));
        queue<pair<int,int>>q;
        queue<pair<int,int>>nq;
        for( int i=0; i<rsize;i++)
        {
            for( int j=0; j<csize;j++)
            {
                if(grid[i][j] == 1)
                {
                    r=i;
                    c=j;
                    visited[r][c]=1;
                    q.push({r,c});
                    break;
                }
            }
            if( visited[r][c]) break;
        }
        grid[r][c]=2;
        nq.push({r,c});
        while(!q.empty())
        {
            int r1 = q.front().first;
            int c1 = q.front().second;
            q.pop();
            for( int i=0; i<4; i++)
            {
                int nrow =r1+ rows[i];
                int ncol = c1 + cols[i];
                if( nrow >=0 && nrow < rsize && ncol >=0 && ncol < csize && grid[nrow][ncol] == 1 && !visited[nrow][ncol])
                {
                    visited[nrow][ncol]=1;
                    grid[nrow][ncol]=2;
                    q.push( {nrow,ncol});
                    nq.push( {nrow,ncol});
                }
            }
        }
        vector<vector<bool>>reached(rsize , vector<bool>( csize,0));
        int level=0;
        bool found=0;
        while(!nq.empty())
        {
            int size = nq.size();
            for( int i=0; i<size;i++)
            {
                int r1 = nq.front().first;
                int c1 = nq.front().second;
                nq.pop();
                // if(grid[r1][c1] == 1) return level;
                for( int i=0; i<4; i++)
                {
                    int nrow =r1+ rows[i];
                    int ncol = c1 + cols[i];
                    if( nrow >=0 && nrow < rsize && ncol >=0 && ncol < csize && !visited[nrow][ncol])
                    {
                        if(grid[nrow][ncol] ==1) return level;
                        visited[nrow][ncol]=1;
                        nq.push( {nrow,ncol});
                    }
                }  
            }
            level++;
        }
        return -1;
        
    }
};