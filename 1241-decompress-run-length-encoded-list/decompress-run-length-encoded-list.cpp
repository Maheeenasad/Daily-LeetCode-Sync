class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> result;
        
        for (int i = 0; i < nums.size(); i += 2) {
            int freq = nums[i];
            int val = nums[i + 1];
            
            // Append 'val' 'freq' times to the result list
            for (int j = 0; j < freq; ++j) {
                result.push_back(val);
            }
        }
        
        return result; 
    }
};