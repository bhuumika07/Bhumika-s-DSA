class Solution {
public:
    int bfs( int row , int col , vector<vector<bool>>&visited , vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({row,col});
        visited[row][col]=1;
        int count=1;
        while(!q.empty())
        {
            auto it = q.front();
            int r= it.first;
            int c= it.second;
            q.pop();
            int delrow[4]={0,-1,0,1};
            int delcol[4]={-1,0,1,0};

            for( int i=0; i<4;i++)
            {
                int nrow= r+ delrow[i];
                int ncol=c+delcol[i];

                if( nrow >=0 && nrow <n && ncol >=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]==1)
                {
                    count++;
                    visited[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }

        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi=0;
        int n= grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m,0));
        for( int i=0; i<n;i++)
        {
            for( int j=0; j<m;j++)
            {
                if(!visited[i][j] && grid[i][j] == 1)
                {
                    int val = bfs(i,j,visited,grid);
                    maxi = max( maxi ,val);
                }
            }
        }
        return maxi;
        
    }
};