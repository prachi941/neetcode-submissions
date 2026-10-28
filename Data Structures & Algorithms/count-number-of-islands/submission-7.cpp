class Solution {
public:

    void dfs(vector<vector<char>>& grid, int r, int c) {

        int rows = grid.size();
        int cols = grid[0].size();

        // 1. Check boundaries and water
        if( r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == '0') {
            return;
        }

        // 2. Mark the current land cell as visited
        grid[r][c] = '0';

        // 3. Explore all four neighbours
        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);

    }

    int numIslands(vector<vector<char>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        int islands = 0;
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == '1') {
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }

        return islands;
    }
};
