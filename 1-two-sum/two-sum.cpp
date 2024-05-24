class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     // Create a map to store numbers and their indices
        unordered_map<int, int> numToIndex;
        
        // Traverse through the array
        for (int i = 0; i < nums.size(); ++i) {
            // Calculate the complement needed to reach the target
            int complement = target - nums[i];
            
            // Check if the complement exists in the map
            if (numToIndex.count(complement) > 0) {
                // Return the indices of the two numbers that add up to the target
                return { numToIndex[complement], i };
            }
            
            // Store the current number and its index in the map
            numToIndex[nums[i]] = i;
        }
        
        // Return an empty vector if no solution is found (although the problem states that each input has exactly one solution)
        return {};
    }
};