class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        // Store all rotten oranges and count fresh ones
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }

        // No fresh oranges
        if (fresh == 0)
            return 0;

        int minutes = 0;
        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

        while (!q.empty()) {
            int size = q.size();
            bool rotted = false;

            while (size--) {
                auto [x, y] = q.front();
                q.pop();

                for (auto [dx, dy] : dir) {
                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx >= 0 && nx < rows &&
                        ny >= 0 && ny < cols &&
                        grid[nx][ny] == 1) {

                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                        rotted = true;
                    }
                }
            }

            if (rotted)
                minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};
