class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;
        int cnt = 0;

        // Give every L a unique bit number
        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                else if (classroom[i][j] == 'L') {
                    id[i][j] = cnt++;
                }
            }
        }

        if (cnt == 0) return 0;

        int fullMask = (1 << cnt) - 1;

        // {row, col, energyLeft, collectedMask}
        queue<array<int, 4>> q;

        // visited[row][col][energyLeft][mask]
        vector vis(
            m,
            vector(
                n,
                vector(
                    energy + 1,
                    vector<bool>(1 << cnt, false)
                )
            )
        );

        q.push({sr, sc, energy, 0});
        vis[sr][sc][energy][0] = true;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto [r, c, energyLeft, mask] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    // Out of bounds
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    // Obstacle
                    if (classroom[nr][nc] == 'X')
                        continue;

                    int newEnergy;
                    int newMask = mask;

                    // Every move costs 1 energy.
                    // If we don't have energy, we cannot move.
                    if (energyLeft == 0)
                        continue;

                    // R restores energy after reaching it
                    if (classroom[nr][nc] == 'R')
                        newEnergy = energy;
                    else
                        newEnergy = energyLeft - 1;

                    // Collect this L
                    if (classroom[nr][nc] == 'L') {
                        newMask |= (1 << id[nr][nc]);
                    }

                    // All L collected
                    if (newMask == fullMask)
                        return steps + 1;

                    if (!vis[nr][nc][newEnergy][newMask]) {
                        vis[nr][nc][newEnergy][newMask] = true;
                        q.push({nr, nc, newEnergy, newMask});
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};