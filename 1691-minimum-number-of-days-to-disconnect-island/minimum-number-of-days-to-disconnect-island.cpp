
class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        // Helper function to count the number of islands in the grid
        auto countIslands = [&](vector<vector<int>>& g) -> int {
            vector<vector<int>> seen(n, vector<int>(m, 0));
            int islandCount = 0;

            function<void(int, int)> dfs = [&](int i, int j) {
                if (i < 0 || i >= n || j < 0 || j >= m || seen[i][j] || g[i][j] == 0) return;
                seen[i][j] = 1;
                dfs(i + 1, j);
                dfs(i - 1, j);
                dfs(i, j + 1);
                dfs(i, j - 1);
            };

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (grid[i][j] == 1 && !seen[i][j]) {
                        ++islandCount;
                        dfs(i, j);
                    }
                }
            }
            return islandCount;
        };

        // If grid is already disconnected
        if (countIslands(grid) != 1) return 0;

        // Try removing one land cell and check if grid gets disconnected
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (countIslands(grid) != 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }

        // If not disconnected after removing one land cell, return 2
        return 2;
    }
};

    