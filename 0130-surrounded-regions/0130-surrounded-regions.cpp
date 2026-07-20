class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n= board.size();
        int m= board[0].size();
        queue<pair<int,int>>q;
        for( int i=0; i<n;i++)
        {
            for( int j=0;j<m;j++)
            {
                if((i==0 || j==0 || i==n-1 | j==m-1) && board[i][j]=='O') q.push({i,j});
            }
        }
        vector<vector<bool>>visited(n, vector<bool>(m,0));
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,-1,0,1};
        vector<vector<bool>>nochange( n, vector<bool>(m,false));
        while(!q.empty())
        {
            auto it = q.front();
            int r=it.first;
            int c= it.second;
            q.pop();
            nochange[r][c]=1;
            for( int i=0; i<4;i++)
            {
                int nrow= r+delrow[i];
                int ncol= c+ delcol[i];
                if( nrow >=0 && nrow< n && ncol>=0 && ncol<m && !visited[nrow][ncol] && board[nrow][ncol]=='O')
                {
                    visited[nrow][ncol]=1;
                    nochange[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }

        for( int i=0; i<n;i++)
        {
            for( int j=0; j<m;j++)
            {
                if( board[i][j]!='X' && !nochange[i][j]) board[i][j]='X';
            }
        }

        
    }
};