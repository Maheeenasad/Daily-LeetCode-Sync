class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
            vector<int> subarraySums;

        // Step 1: Generate all subarray sums
        for (int i = 0; i < n; ++i) {
            int currentSum = 0;
            for (int j = i; j < n; ++j) {
                currentSum += nums[j];
                subarraySums.push_back(currentSum);
            }
        }

        // Step 2: Sort the subarray sums
        sort(subarraySums.begin(), subarraySums.end());

        // Step 3: Sum the required range
        long long result = 0;
        int MOD = 1e9 + 7;
        for (int k = left - 1; k <= right - 1; ++k) {
            result = (result + subarraySums[k]) % MOD;
        }

        return result;
    }
};