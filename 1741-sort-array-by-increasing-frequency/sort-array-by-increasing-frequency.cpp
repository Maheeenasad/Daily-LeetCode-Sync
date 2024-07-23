class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
         unordered_map<int, int> frequency;
        
        // Count the frequency of each number
        for (int num : nums) {
            frequency[num]++;
        }
        
        // Sort the array with custom comparator
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (frequency[a] == frequency[b]) {
                return a > b; // If frequencies are the same, sort by value in decreasing order
            }
            return frequency[a] < frequency[b]; // Otherwise, sort by frequency in increasing order
        });
        
        return nums;  
    }
};