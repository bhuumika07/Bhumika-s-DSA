class Solution {
public:
    long long bfs( int row , int col , vector<vector<bool>>&visited , vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({row,col});
        visited[row][col]=1;
        long long count=grid[row][col];
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

                if( nrow >=0 && nrow <n && ncol >=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]!=0)
                {
                    count+=grid[nrow][ncol];
                    visited[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }

        }
        return count;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int count=0;
        int n= grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m,0));
        for( int i=0; i<n;i++)
        {
            for( int j=0; j<m;j++)
            {
                if(!visited[i][j] && grid[i][j] != 0)
                {
                    long long val = bfs(i,j,visited,grid);
                   if(val%k==0) count++;
                }
            }
        }
        return count;
        
    }
};