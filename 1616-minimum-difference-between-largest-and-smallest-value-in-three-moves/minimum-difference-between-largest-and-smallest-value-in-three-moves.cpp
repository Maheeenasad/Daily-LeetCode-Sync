class Solution {
public:
    int minDifference(vector<int>& nums) {
      int n = nums.size();
        if (n <= 4) {
            return 0;
        }
        
        std::sort(nums.begin(), nums.end());
        
        int minDiff = INT_MAX;
        minDiff = std::min(minDiff, nums[n-1] - nums[3]); // Remove the three smallest elements
        minDiff = std::min(minDiff, nums[n-2] - nums[2]); // Remove two smallest and one largest
        minDiff = std::min(minDiff, nums[n-3] - nums[1]); // Remove one smallest and two largest
        minDiff = std::min(minDiff, nums[n-4] - nums[0]); // Remove the three largest elements
        
        return minDiff;   
    }
};