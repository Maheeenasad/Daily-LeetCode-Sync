class Solution {
public:
    int minSwaps(vector<int>& nums) {
         int n = nums.size();
        int count1 = 0;
        
        // Count total number of 1's in the array
        for (int num : nums) {
            if (num == 1) count1++;
        }
        
        // If there are no 1's, no swaps needed
        if (count1 == 0) return 0;
        
        // Create a circular array by doubling it
        vector<int> nums2 = nums;
        nums2.insert(nums2.end(), nums.begin(), nums.end());
        
        // Find the maximum number of 1's in any window of size count1
        int maxOnes = 0, currentOnes = 0;
        for (int i = 0; i < count1; i++) {
            if (nums2[i] == 1) currentOnes++;
        }
        maxOnes = currentOnes;
        
        for (int i = count1; i < nums2.size(); i++) {
            if (nums2[i] == 1) currentOnes++;
            if (nums2[i - count1] == 1) currentOnes--;
            maxOnes = max(maxOnes, currentOnes);
        }
        
        // Minimum swaps needed
        return count1 - maxOnes;
    }
};