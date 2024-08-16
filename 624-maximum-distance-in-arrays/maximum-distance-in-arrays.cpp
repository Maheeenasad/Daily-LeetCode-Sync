class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
         int min_value = arrays[0][0];
        int max_value = arrays[0].back();
        int max_distance = 0;
        
        for (int i = 1; i < arrays.size(); i++) {
            // Calculate distance considering the current array
            max_distance = max(max_distance, abs(arrays[i].back() - min_value));
            max_distance = max(max_distance, abs(max_value - arrays[i][0]));
            
            // Update global min and max
            min_value = min(min_value, arrays[i][0]);
            max_value = max(max_value, arrays[i].back());
        }
        
        return max_distance;
    }
};