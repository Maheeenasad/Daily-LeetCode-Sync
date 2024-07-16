class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        // Step 1: Find the maximum number of candies
        int maxCandies = *max_element(candies.begin(), candies.end());
        
        // Step 2 and 3: Check each kid's candies with extraCandies added
        vector<bool> result(candies.size());
        for (int i = 0; i < candies.size(); ++i) {
            result[i] = (candies[i] + extraCandies >= maxCandies);
        }
        
        return result;  
    }
};