class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
            int m = grid1.size();
        int n = grid1[0].size();
        int count = 0;

        // Function to perform DFS and check if the current island in grid2 is a sub-island.
        std::function<bool(int, int)> dfs = [&](int i, int j) {
            // If out of bounds or water in grid2, return true (because it's not affecting the sub-island status).
            if (i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] == 0) return true;
            
            // Mark the current cell as visited in grid2
            grid2[i][j] = 0;

            // Check if this part of the island in grid2 is not in grid1
            bool isSubIsland = grid1[i][j] == 1;
            
            // Explore all four directions
            isSubIsland &= dfs(i - 1, j);
            isSubIsland &= dfs(i + 1, j);
            isSubIsland &= dfs(i, j - 1);
            isSubIsland &= dfs(i, j + 1);
            
            return isSubIsland;
        };

        // Iterate over every cell in grid2
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j] == 1) { // Found an island in grid2
                    if (dfs(i, j)) {
                        // If dfs returns true, it means all parts of this island in grid2 are also in grid1
                        count++;
                    }
                }
            }
        }

        return count;
    }
};