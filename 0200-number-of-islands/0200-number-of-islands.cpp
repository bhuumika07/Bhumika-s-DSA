class Solution {
public:
void bfs( int row, int col , vector<vector<bool>> & visited, vector<vector<char>>& grid)
{
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,-1,0,1};
    int n=visited.size();
    int m=visited[0].size();
    queue<pair<int,int>>q;
    q.push({row,col});
    while(!q.empty())
    {
        auto it = q.front();
        int r=it.first;
        int c =it.second;
        q.pop();
        for( int i=0; i<4;i++)
        {
            int nrow=r+delrow[i];
            int ncol=c+delcol[i];
            if( nrow >=0 && nrow < n && ncol >=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]=='1' )
            {
                visited[nrow][ncol]=1;
                q.push({nrow,ncol});
            }
        }

    }
    
}
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int n=grid.size();
        int m= grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for( int i=0; i<n;i++)
        {
            for( int j=0; j<m;j++)
            {
                if(!visited[i][j] && grid[i][j]=='1')
                {
                    count++;
                    visited[i][j]=1;
                    bfs(i,j,visited,grid);
                }
            }
        }
        return count;
        
    }
};