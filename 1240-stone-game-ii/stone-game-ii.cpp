class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));  // DP table with sufficient size

        // Calculate suffix sums, DP transitions, etc.
        vector<int> suffixSum(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int m = 1; m <= n; ++m) {
                for (int x = 1; x <= 2 * m && i + x <= n; ++x) {
                    if (i + x <= n) {  // Ensure i + x is within bounds
                        dp[i][m] = max(dp[i][m], suffixSum[i] - dp[i + x][min(n, max(m, x))]); 
                        // Use min to ensure you stay within the dp bounds.
                    }
                }
            }
        }

        return dp[0][1];  // Final result for the optimal number of stones Alice can get
    }
};
