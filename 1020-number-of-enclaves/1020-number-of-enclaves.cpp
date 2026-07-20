class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n= grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited( n , vector<bool>(m,false));
        queue<pair<int,int>>q;
        int count=0;
        for( int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1) {
                    count++;
                    if( i==0 || i== n-1 || j==0 || j==m-1) q.push({i,j});
                }
            }
        }
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,-1,0,1};
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int r = it.first;
            int c=it.second;
            if(!visited[r][c])
            {
                visited[r][c]=1;
                count--;
            }
          
            for( int i=0; i<4;i++)
            {
                int nrow= r+delrow[i];
                int ncol=c+delcol[i];

                if( nrow >= 0 && nrow <n && ncol >=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]==1)
                {
                    visited[nrow][ncol]=1;
                    count--;
                    q.push({nrow,ncol});
                }
            }

        }
        return count;
        
    }
};