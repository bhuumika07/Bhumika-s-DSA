class Solution {
public:
    bool doit( int row , int col , vector<vector<bool>>&visited,vector<vector<int>>& grid1, vector<vector<int>>& grid2 )
    {
        int n= grid1.size();
        int m=grid1[0].size();
        visited[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,-1,0,1};
        bool possible=1;
        while(!q.empty())
        {
            auto it = q.front();
            int r= it.first;
            int c = it.second;
            q.pop();
            for( int i=0; i<4;i++)
            {
                int nrow= r+delrow[i];
                int ncol=c+delcol[i];
                if( nrow>=0 && nrow<n && ncol >=0 && ncol <m &&!visited[nrow][ncol] && grid2[nrow][ncol]==1 )
                {
                    if( grid1[nrow][ncol] != 1) possible=0;
                    visited[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
           
        }
         return possible;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n= grid1.size();
        int m=grid1[0].size();
        vector<vector<bool>>visited1(n ,vector<bool>(m,false));
        vector<vector<bool>>visited2(n ,vector<bool>(m,false));
        int count=0;
        for( int i=0;i<n;i++)
        {
            for( int j=0; j<m;j++)
            {
                if( !visited1[i][j] && grid2[i][j]==1 && grid1[i][j]==1)
                {
                    if(doit(i,j,visited1,grid1,grid2)) count++;
                }
            }
        }
        return count;

        
    }
};