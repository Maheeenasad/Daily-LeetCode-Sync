class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        std::vector<int> result;
        
        // Step 1: Find the minimum element in each row and their column indices
        std::vector<int> rowMin(matrix.size());
        std::vector<int> rowMinColIdx(matrix.size());
        for (int i = 0; i < matrix.size(); ++i) {
            int minVal = matrix[i][0];
            int minColIdx = 0;
            for (int j = 1; j < matrix[i].size(); ++j) {
                if (matrix[i][j] < minVal) {
                    minVal = matrix[i][j];
                    minColIdx = j;
                }
            }
            rowMin[i] = minVal;
            rowMinColIdx[i] = minColIdx;
        }
        
        // Step 2: Find the maximum element in each column
        std::vector<int> colMax(matrix[0].size(), INT_MIN);
        for (int j = 0; j < matrix[0].size(); ++j) {
            for (int i = 0; i < matrix.size(); ++i) {
                colMax[j] = std::max(colMax[j], matrix[i][j]);
            }
        }
        
        // Step 3: Check if the row minimum is the column maximum
        for (int i = 0; i < rowMin.size(); ++i) {
            int colIdx = rowMinColIdx[i];
            if (rowMin[i] == colMax[colIdx]) {
                result.push_back(rowMin[i]);
            }
        }
        
        return result;  
    }
};