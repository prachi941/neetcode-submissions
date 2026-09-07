class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int minutes = 0;

        int directions[4][2] = {
            {-1, 0},
            {0, 1},
            {1, 0},
            {0, -1}
        };

        while (!q.empty() && fresh > 0) {

            int size = q.size();

            for (int i = 0; i < size; i++) {

                auto [r, c] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {

                    int nr = r + directions[d][0];
                    int nc = c + directions[d][1];

                    if (nr < 0 || nc < 0 ||
                        nr >= n || nc >= m) {
                        continue;
                    }

                    if (grid[nr][nc] != 1) {
                        continue;
                    }

                    grid[nr][nc] = 2;
                    fresh--;

                    q.push({nr, nc});
                }
            }

            minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};