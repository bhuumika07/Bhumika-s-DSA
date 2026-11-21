class Solution {
public:
    void doit( vector<vector<int>>&visited , vector<vector<char>> &board, int r ,int c){
        int n = board.size();
        int m= board[0].size();

        int rows[] = {-1,1,0,0};
        int cols[] = {0,0,-1,1};

        visited[r][c] = -1;
        for( int i=0; i<4; i++){
            int nr = r + rows[i];
            int nc = c + cols[i];

            if( nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if(board[nr][nc] != 'O' || visited[nr][nc] != 0) continue;
            doit(visited,board,nr,nc);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        // i will mark all the regions in the board that are connected to the boundry.
        vector< vector<int>> visited( n , vector<int>(m , 0));
        for( int i=0; i<n;i++){
            for( int j=0; j<m;j++){
                if(board[i][j] == 'O' && ( i == 0 || j==0 || i==n-1 || j == m-1) && visited[i][j] == 0){
                    doit(visited,board,i,j);
                }
            }
        }

        for( int i = 0; i<n; i++){
            for( int j=0; j<m;j++){
                if( visited[i][j] != -1 && board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};