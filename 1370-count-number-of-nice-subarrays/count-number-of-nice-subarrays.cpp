class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // Transform the array into a binary array where 1 represents an odd number and 0 represents an even number
        for (int& num : nums) {
            num = num % 2;
        }

        // Use a hash map to count prefix sums
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1; // To handle the case when a subarray starts from index 0
        
        int prefixSum = 0;
        int count = 0;

        // Traverse the array and calculate the prefix sums
        for (int num : nums) {
            prefixSum += num;
            // If there's a prefix sum that is exactly k less than the current prefix sum, it means there is a subarray ending here with exactly k odd numbers
            if (prefixSumCount.find(prefixSum - k) != prefixSumCount.end()) {
                count += prefixSumCount[prefixSum - k];
            }
            // Add the current prefix sum to the hash map
            prefixSumCount[prefixSum]++;
        }

        return count; 
    }
};