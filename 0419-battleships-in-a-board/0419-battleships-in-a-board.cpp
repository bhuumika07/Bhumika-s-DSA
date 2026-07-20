class Solution {
public:
    void bfs( int row , int col , vector<vector<bool>>&visited ,vector<vector<char>>& board )
    {
        visited[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,-1,0,1};
        int n= board.size();
        int m=board[0].size();

        while(!q.empty())
        {
            auto it = q.front();
            int r= it.first;
            int c=it.second;
            q.pop();
            for( int i=0; i<4;i++)
            {
                int nrow= r+delrow[i];
                int ncol=c+delcol[i];

                if( nrow >=0 && nrow<n && ncol >=0 && ncol<m && !visited[nrow][ncol] && board[nrow][ncol]=='X')
                {
                    visited[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int count=0;
        int n= board.size();
        int m=board[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m,0));
        for( int i=0; i<n;i++)
        {
            for( int j=0; j<m;j++)
            {
                if(!visited[i][j] && board[i][j]=='X')
                {
                    count++;
                    bfs(i,j,visited,board);
                }
            }
        }
        return count;
        
    }
};