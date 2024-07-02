class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
          unordered_map<int, int> counts;
        vector<int> result;
        
        // Count occurrences of each element in nums1
        for (int num : nums1) {
            counts[num]++;
        }
        
        // Iterate over nums2 and collect the common elements
        for (int num : nums2) {
            if (counts[num] > 0) {
                result.push_back(num);
                counts[num]--;
            }
        }
        
        return result;
    }
};