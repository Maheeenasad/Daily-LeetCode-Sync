class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
          // Step 1: Sort the array
        sort(nums.begin(), nums.end());
        
        int moves = 0;  // To keep track of the total number of moves
        
        // Step 2: Iterate through the sorted array and make elements unique
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i - 1]) {
                // Calculate how many moves needed to make nums[i] unique
                int increment = nums[i - 1] - nums[i] + 1;
                nums[i] += increment;
                moves += increment;
            }
        }
        
        return moves;
    }
};