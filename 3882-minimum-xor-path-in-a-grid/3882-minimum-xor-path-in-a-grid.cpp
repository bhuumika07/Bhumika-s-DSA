class Solution {
public:
    int ans = INT_MAX;

    void dfs(vector<vector<int>>& grid, int r, int c,
             int xr, vector<vector<vector<bool>>>& visited)
    {
        int n = grid.size();
        int m = grid[0].size();

        xr ^= grid[r][c];

        if(visited[r][c][xr]) return;

        visited[r][c][xr] = true;

        if(r == n-1 && c == m-1)
        {
            ans = min(ans, xr);
            return;
        }

        int rows[] = {0, 1};
        int cols[] = {1, 0};

        for(int i = 0; i < 2; i++)
        {
            int nr = r + rows[i];
            int nc = c + cols[i];

            if(nr >= n || nc >= m) continue;

            dfs(grid, nr, nc, xr, visited);
        }
    }

    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<bool>>> visited(
            n, vector<vector<bool>>(m, vector<bool>(1024, false))
        );

        dfs(grid, 0, 0, 0, visited);

        return ans;
    }
};