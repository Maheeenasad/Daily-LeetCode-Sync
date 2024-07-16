class Solution {
private:
    int total_xor_sum = 0;
    
    void dfs(vector<int>& nums, int index, int current_xor) {
        if (index == nums.size()) {
            total_xor_sum += current_xor;
            return;
        }
        
        // Include nums[index] in the subset
        dfs(nums, index + 1, current_xor ^ nums[index]);
        
        // Exclude nums[index] from the subset
        dfs(nums, index + 1, current_xor);
    }
    
public:
    int subsetXORSum(vector<int>& nums) {
        dfs(nums, 0, 0);
        return total_xor_sum;
    }
};