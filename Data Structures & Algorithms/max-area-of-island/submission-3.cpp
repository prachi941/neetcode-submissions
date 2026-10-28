class Solution {
public:

    int dfs(vector<vector<int>>& grid, int r, int c) {

        int rows = grid.size();
        int cols = grid[0].size();

        if(r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) {
            return 0;
        }

        grid[r][c] = 0;

        // Count the current cell
        int area = 1;

        area += dfs(grid, r+1, c);
        area += dfs(grid, r-1, c);
        area += dfs(grid, r, c-1);
        area += dfs(grid, r, c+1);

        return area;
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        int maxArea = 0;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1) {
                    int area = dfs(grid, i, j);
                    maxArea = max(maxArea, area);
                }
            }

        }

        return maxArea;
    }
};
