class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
         int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        // Check every 3x3 subgrid
        for (int i = 0; i <= rows - 3; ++i) {
            for (int j = 0; j <= cols - 3; ++j) {
                if (isMagicSquare(grid, i, j)) {
                    ++count;
                }
            }
        }

        return count;
    }

private:
    bool isMagicSquare(const std::vector<std::vector<int>>& grid, int r, int c) {
        // Check if all numbers are distinct and in the range 1 to 9
        std::unordered_set<int> seen;
        for (int i = r; i < r + 3; ++i) {
            for (int j = c; j < c + 3; ++j) {
                int num = grid[i][j];
                if (num < 1 || num > 9 || seen.count(num)) {
                    return false;
                }
                seen.insert(num);
            }
        }

        // Check if the sum of rows, columns, and diagonals is 15
        int sum1 = grid[r][c] + grid[r][c+1] + grid[r][c+2];
        int sum2 = grid[r+1][c] + grid[r+1][c+1] + grid[r+1][c+2];
        int sum3 = grid[r+2][c] + grid[r+2][c+1] + grid[r+2][c+2];

        int sum4 = grid[r][c] + grid[r+1][c] + grid[r+2][c];
        int sum5 = grid[r][c+1] + grid[r+1][c+1] + grid[r+2][c+1];
        int sum6 = grid[r][c+2] + grid[r+1][c+2] + grid[r+2][c+2];

        int sum7 = grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2];
        int sum8 = grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c];

        return sum1 == 15 && sum2 == 15 && sum3 == 15 &&
               sum4 == 15 && sum5 == 15 && sum6 == 15 &&
               sum7 == 15 && sum8 == 15; 
    }
};