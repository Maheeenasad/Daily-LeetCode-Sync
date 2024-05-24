class Solution {
public:
    int findMaxK(vector<int>& nums) {
         // Create a set to store the numbers we encounter
        unordered_set<int> seen;
        int max_k = -1;

        // Traverse through the array
        for (int num : nums) {
            // Check if the negative counterpart exists in the set
            if (seen.count(-num) > 0) {
                // Update max_k to be the larger of current max_k and absolute value of num
                max_k = max(max_k, abs(num));
            }
            // Add the current number to the set
            seen.insert(num);
        }

        return max_k;
    }

};