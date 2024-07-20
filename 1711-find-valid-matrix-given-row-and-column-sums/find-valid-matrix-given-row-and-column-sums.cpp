class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
           int numRows = rowSum.size();
        int numCols = colSum.size();
        vector<vector<int>> matrix(numRows, vector<int>(numCols, 0));
        
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                int val = min(rowSum[i], colSum[j]);
                matrix[i][j] = val;
                rowSum[i] -= val;
                colSum[j] -= val;
            }
        }
        
        return matrix;
    }
};