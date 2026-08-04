class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        int row[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int col[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int live = 0;

                for (int k = 0; k < 8; k++) {
                    int x = i + row[k];
                    int y = j + col[k];

                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        if (board[x][y] == 1 || board[x][y] == 2)
                            live++;
                    }
                }

                if (board[i][j] == 1) {
                    if (live < 2 || live > 3)
                        board[i][j] = 2;   // Live -> Dead
                } else {
                    if (live == 3)
                        board[i][j] = 3;   // Dead -> Live
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 2)
                    board[i][j] = 0;
                else if (board[i][j] == 3)
                    board[i][j] = 1;
            }
        }
    }
};