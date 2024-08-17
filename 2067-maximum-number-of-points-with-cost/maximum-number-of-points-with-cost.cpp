class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
           int m = points.size();
        int n = points[0].size();
        
        vector<long long> prev(n, 0);
        
        // Initialize with the first row
        for (int c = 0; c < n; ++c) {
            prev[c] = points[0][c];
        }
        
        // Process each subsequent row
        for (int r = 1; r < m; ++r) {
            vector<long long> left(n, 0), right(n, 0), curr(n, 0);
            
            // Fill the left max array
            left[0] = prev[0];
            for (int c = 1; c < n; ++c) {
                left[c] = max(left[c-1], prev[c] + c);
            }
            
            // Fill the right max array
            right[n-1] = prev[n-1] - (n-1);
            for (int c = n-2; c >= 0; --c) {
                right[c] = max(right[c+1], prev[c] - c);
            }
            
            // Update current row DP using left and right max arrays
            for (int c = 0; c < n; ++c) {
                curr[c] = points[r][c] + max(left[c] - c, right[c] + c);
            }
            
            prev = curr; // Move to the next row
        }
        
        // The answer is the maximum value in the last row
        return *max_element(prev.begin(), prev.end());
    }
};