class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
          vector<vector<int>> result;
        int total_cells = rows * cols;
        
        // Directions: right, down, left, up
        vector<int> dirX = {0, 1, 0, -1};
        vector<int> dirY = {1, 0, -1, 0};
        
        result.push_back({rStart, cStart});
        if (total_cells == 1) return result; // Edge case for a single cell
        
        int steps = 1; // Number of steps in the current direction
        int d = 0; // Current direction index (0 = right, 1 = down, 2 = left, 3 = up)
        
        int r = rStart;
        int c = cStart;
        
        while (result.size() < total_cells) {
            for (int i = 0; i < 2; ++i) { // There are two passes for each step size
                for (int j = 0; j < steps; ++j) {
                    r += dirX[d];
                    c += dirY[d];
                    if (r >= 0 && r < rows && c >= 0 && c < cols) {
                        result.push_back({r, c});
                        if (result.size() == total_cells) return result;
                    }
                }
                d = (d + 1) % 4; // Move to the next direction
            }
            ++steps; // Increase the step size after completing a full cycle
        }
        
        return result;
    }
};