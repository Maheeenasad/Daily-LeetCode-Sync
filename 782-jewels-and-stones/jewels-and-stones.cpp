class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
         std::unordered_set<char> jewelSet(jewels.begin(), jewels.end());
        
        int count = 0;
        
        // Iterate through each stone
        for (char stone : stones) {
            // If the stone is in the jewel set, increment the count
            if (jewelSet.find(stone) != jewelSet.end()) {
                ++count;
            }
        }
        
        return count;
    }
};